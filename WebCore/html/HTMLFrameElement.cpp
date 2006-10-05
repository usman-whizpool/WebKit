/**
 * This file is part of the DOM implementation for KDE.
 *
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 *           (C) 2000 Simon Hausmann (hausmann@kde.org)
 *           (C) 2001 Dirk Mueller (mueller@kde.org)
 * Copyright (C) 2004, 2006 Apple Computer, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
#include "config.h"
#include "HTMLFrameElement.h"

#include "csshelper.h"
#include "Document.h"
#include "EventNames.h"
#include "Frame.h"
#include "FrameTree.h"
#include "FrameView.h"
#include "HTMLNames.h"
#include "HTMLFrameSetElement.h"
#include "Page.h"
#include "RenderFrame.h"

namespace WebCore {

using namespace EventNames;
using namespace HTMLNames;

HTMLFrameElement::HTMLFrameElement(Document *doc)
    : HTMLElement(frameTag, doc)
{
    init();
}

HTMLFrameElement::HTMLFrameElement(const QualifiedName& tagName, Document *doc)
    : HTMLElement(tagName, doc)
{
    init();
}

void HTMLFrameElement::init()
{
    m_frameBorder = true;
    m_frameBorderSet = false;
    m_marginWidth = -1;
    m_marginHeight = -1;
    m_scrolling = ScrollbarAuto;
    m_noResize = false;
    m_viewSource = false;
}

HTMLFrameElement::~HTMLFrameElement()
{
}

bool HTMLFrameElement::isURLAllowed(const AtomicString& URLString) const
{
    if (URLString.isEmpty())
        return true;

    KURL completeURL(document()->completeURL(URLString.deprecatedString()));
    completeURL.setRef(DeprecatedString::null);

    // Don't allow more than 200 total frames in a set. This seems
    // like a reasonable upper bound, and otherwise mutually recursive
    // frameset pages can quickly bring the program to its knees with
    // exponential growth in the number of frames.

    // FIXME: This limit could be higher, but WebKit has some
    // algorithms that happen while loading which appear to be N^2 or
    // worse in the number of frames
    if (Frame* parentFrame = document()->frame())
        if (parentFrame->page()->frameCount() > 200)
            return false;

    // We allow one level of self-reference because some sites depend on that.
    // But we don't allow more than one.
    bool foundSelfReference = false;
    for (Frame* frame = document()->frame(); frame; frame = frame->tree()->parent()) {
        KURL frameURL = frame->url();
        frameURL.setRef(DeprecatedString::null);
        if (frameURL == completeURL) {
            if (foundSelfReference)
                return false;
            foundSelfReference = true;
        }
    }
    
    return true;
}

void HTMLFrameElement::openURL()
{
    if (!isURLAllowed(m_URL))
        return;

    if (m_URL.isEmpty())
        m_URL = "about:blank";

    document()->frame()->requestFrame(this, m_URL, m_name);

    if (contentFrame())
        contentFrame()->setInViewSourceMode(viewSourceMode());
}

void HTMLFrameElement::parseMappedAttribute(MappedAttribute *attr)
{
    if (attr->name() == srcAttr)
        setLocation(parseURL(attr->value()));
    else if (attr->name() == idAttr) {
        // Important to call through to base for the id attribute so the hasID bit gets set.
        HTMLElement::parseMappedAttribute(attr);
        m_name = attr->value();
    } else if (attr->name() == nameAttr) {
        m_name = attr->value();
        // FIXME: If we are already attached, this doesn't actually change the frame's name.
        // FIXME: If we are already attached, this doesn't check for frame name
        // conflicts and generate a unique frame name.
    } else if (attr->name() == frameborderAttr) {
        m_frameBorder = attr->value().toInt();
        m_frameBorderSet = !attr->isNull();
        // FIXME: If we are already attached, this has no effect.
    } else if (attr->name() == marginwidthAttr) {
        m_marginWidth = attr->value().toInt();
        // FIXME: If we are already attached, this has no effect.
    } else if (attr->name() == marginheightAttr) {
        m_marginHeight = attr->value().toInt();
        // FIXME: If we are already attached, this has no effect.
    } else if (attr->name() == noresizeAttr) {
        m_noResize = true;
        // FIXME: If we are already attached, this has no effect.
    } else if (attr->name() == scrollingAttr) {
        // Auto and yes both simply mean "allow scrolling." No means "don't allow scrolling."
        if (equalIgnoringCase(attr->value(), "auto") || equalIgnoringCase(attr->value(), "yes"))
            m_scrolling = ScrollbarAuto;
        else if (equalIgnoringCase(attr->value(), "no"))
            m_scrolling = ScrollbarAlwaysOff;
        // FIXME: If we are already attached, this has no effect.
    } else if (attr->name() == viewsourceAttr) {
        m_viewSource = !attr->isNull();
        if (contentFrame())
            contentFrame()->setInViewSourceMode(viewSourceMode());
    } else if (attr->name() == onloadAttr) {
        setHTMLEventListener(loadEvent, attr);
    } else if (attr->name() == onbeforeunloadAttr) {
        // FIXME: should <frame> elements have beforeunload handlers?
        setHTMLEventListener(beforeunloadEvent, attr);
    } else if (attr->name() == onunloadAttr) {
        setHTMLEventListener(unloadEvent, attr);
    } else
        HTMLElement::parseMappedAttribute(attr);
}

bool HTMLFrameElement::rendererIsNeeded(RenderStyle *style)
{
    // Ignore display: none.
    return isURLAllowed(m_URL);
}

RenderObject *HTMLFrameElement::createRenderer(RenderArena *arena, RenderStyle *style)
{
    return new (arena) RenderFrame(this);
}

void HTMLFrameElement::insertedIntoDocument()
{
    HTMLElement::insertedIntoDocument();
    
    m_name = getAttribute(nameAttr);
    if (m_name.isNull())
        m_name = getAttribute(idAttr);

    if (Frame* parentFrame = document()->frame())
        m_name = parentFrame->tree()->uniqueChildName(m_name);
}

void HTMLFrameElement::attach()
{
    HTMLElement::attach();
    
    if (hasTagName(frameTag)) {
        if (HTMLFrameSetElement* frameSetElement = containingFrameSetElement()) {
            if (!m_frameBorderSet)
                m_frameBorder = frameSetElement->frameBorder();
            if (!m_noResize)
                m_noResize = frameSetElement->noResize();
        }
    }
        
    if (!contentFrame())
        openURL();
}

void HTMLFrameElement::willRemove()
{
    if (Frame* frame = contentFrame()) {
        frame->disconnectOwnerElement();
        frame->frameDetached();
    }

    HTMLElement::willRemove();
}

void HTMLFrameElement::setLocation(const String& str)
{
    m_URL = AtomicString(str);

    if (attached())
        openURL();
}

bool HTMLFrameElement::isFocusable() const
{
    return renderer();
}

void HTMLFrameElement::setFocus(bool received)
{
    HTMLElement::setFocus(received);
    RenderFrame *renderFrame = static_cast<RenderFrame *>(renderer());
    if (!renderFrame || !renderFrame->widget())
        return;
    if (received)
        renderFrame->widget()->setFocus();
    else
        renderFrame->widget()->clearFocus();
}

Frame* HTMLFrameElement::contentFrame() const
{
    // Start with the part that contains this element, our ownerDocument.
    Frame* parentFrame = document()->frame();
    if (!parentFrame)
        return 0;

    // Find the part for the subframe that this element represents.
    return parentFrame->tree()->child(m_name);
}

Document* HTMLFrameElement::contentDocument() const
{
    Frame* frame = contentFrame();
    if (!frame)
        return 0;
    return frame->document();
}

HTMLFrameSetElement* HTMLFrameElement::containingFrameSetElement() const
{
    for (Node* node = parentNode(); node; node = node->parentNode())
        if (node->hasTagName(framesetTag))
            return static_cast<HTMLFrameSetElement*>(node);

    return 0;
}

bool HTMLFrameElement::isURLAttribute(Attribute *attr) const
{
    return attr->name() == srcAttr;
}

String HTMLFrameElement::frameBorder() const
{
    return getAttribute(frameborderAttr);
}

void HTMLFrameElement::setFrameBorder(const String &value)
{
    setAttribute(frameborderAttr, value);
}

String HTMLFrameElement::longDesc() const
{
    return getAttribute(longdescAttr);
}

void HTMLFrameElement::setLongDesc(const String &value)
{
    setAttribute(longdescAttr, value);
}

String HTMLFrameElement::marginHeight() const
{
    return getAttribute(marginheightAttr);
}

void HTMLFrameElement::setMarginHeight(const String &value)
{
    setAttribute(marginheightAttr, value);
}

String HTMLFrameElement::marginWidth() const
{
    return getAttribute(marginwidthAttr);
}

void HTMLFrameElement::setMarginWidth(const String &value)
{
    setAttribute(marginwidthAttr, value);
}

String HTMLFrameElement::name() const
{
    return getAttribute(nameAttr);
}

void HTMLFrameElement::setName(const String &value)
{
    setAttribute(nameAttr, value);
}

void HTMLFrameElement::setNoResize(bool noResize)
{
    setAttribute(noresizeAttr, noResize ? "" : 0);
}

String HTMLFrameElement::scrolling() const
{
    return getAttribute(scrollingAttr);
}

void HTMLFrameElement::setScrolling(const String &value)
{
    setAttribute(scrollingAttr, value);
}

String HTMLFrameElement::src() const
{
    return document()->completeURL(getAttribute(srcAttr));
}

void HTMLFrameElement::setSrc(const String &value)
{
    setAttribute(srcAttr, value);
}

int HTMLFrameElement::frameWidth() const
{
    if (!renderer())
        return 0;
    
    document()->updateLayoutIgnorePendingStylesheets();
    return renderer()->width();
}

int HTMLFrameElement::frameHeight() const
{
    if (!renderer())
        return 0;
    
    document()->updateLayoutIgnorePendingStylesheets();
    return renderer()->height();
}

}
