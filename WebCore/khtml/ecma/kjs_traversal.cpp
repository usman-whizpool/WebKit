/*
 *  This file is part of the KDE libraries
 *  Copyright (C) 2001 Peter Kelly (pmk@post.com)
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "config.h"
#include "kjs_traversal.h"

#include "DocumentImpl.h"
#include "Frame.h"
#include "kjs_proxy.h"

#include "kjs_traversal.lut.h"

using namespace WebCore;

namespace KJS {

// -------------------------------------------------------------------------

const ClassInfo DOMNodeIterator::info = { "NodeIterator", 0, &DOMNodeIteratorTable, 0 };
/*
@begin DOMNodeIteratorTable 5
  root				DOMNodeIterator::Root			DontDelete|ReadOnly
  whatToShow			DOMNodeIterator::WhatToShow		DontDelete|ReadOnly
  filter			DOMNodeIterator::Filter			DontDelete|ReadOnly
  expandEntityReferences	DOMNodeIterator::ExpandEntityReferences	DontDelete|ReadOnly
  referenceNode	DOMNodeIterator::ReferenceNode	DontDelete|ReadOnly
  pointerBeforeReferenceNode DOMNodeIterator::PointerBeforeReferenceNode	DontDelete|ReadOnly
@end
@begin DOMNodeIteratorProtoTable 3
  nextNode	DOMNodeIterator::NextNode	DontDelete|Function 0
  previousNode	DOMNodeIterator::PreviousNode	DontDelete|Function 0
  detach	DOMNodeIterator::Detach		DontDelete|Function 0
@end
*/
KJS_DEFINE_PROTOTYPE(DOMNodeIteratorProto)
KJS_IMPLEMENT_PROTOFUNC(DOMNodeIteratorProtoFunc)
KJS_IMPLEMENT_PROTOTYPE("DOMNodeIterator",DOMNodeIteratorProto,DOMNodeIteratorProtoFunc)

DOMNodeIterator::DOMNodeIterator(ExecState *exec, NodeIteratorImpl *ni)
  : m_impl(ni)
{
  setPrototype(DOMNodeIteratorProto::self(exec));
}

DOMNodeIterator::~DOMNodeIterator()
{
  ScriptInterpreter::forgetDOMObject(m_impl.get());
}

void DOMNodeIterator::mark()
{
    m_impl->filter()->mark();
    DOMObject::mark();
}

bool DOMNodeIterator::getOwnPropertySlot(ExecState *exec, const Identifier& propertyName, PropertySlot& slot)
{
  return getStaticValueSlot<DOMNodeIterator, DOMObject>(exec, &DOMNodeIteratorTable, this, propertyName, slot);
}

JSValue *DOMNodeIterator::getValueProperty(ExecState *exec, int token) const
{
  NodeIteratorImpl &ni = *m_impl;
  switch (token) {
  case Root:
    return toJS(exec,ni.root());
  case WhatToShow:
    return jsNumber(ni.whatToShow());
  case Filter:
    return toJS(exec,ni.filter());
  case ExpandEntityReferences:
    return jsBoolean(ni.expandEntityReferences());
  case ReferenceNode:
    return toJS(exec,ni.referenceNode());
  case PointerBeforeReferenceNode:
    return jsBoolean(ni.pointerBeforeReferenceNode());
 default:
   return 0;
  }
}

JSValue *DOMNodeIteratorProtoFunc::callAsFunction(ExecState *exec, JSObject *thisObj, const List &)
{
  if (!thisObj->inherits(&KJS::DOMNodeIterator::info))
    return throwError(exec, TypeError);
  DOMExceptionTranslator exception(exec);
  NodeIteratorImpl &nodeIterator = *static_cast<DOMNodeIterator *>(thisObj)->impl();
  switch (id) {
  case DOMNodeIterator::PreviousNode:
    return toJS(exec,nodeIterator.previousNode(exception));
  case DOMNodeIterator::NextNode:
    return toJS(exec,nodeIterator.nextNode(exception));
  case DOMNodeIterator::Detach:
    nodeIterator.detach(exception);
    return jsUndefined();
  }
  return jsUndefined();
}

JSValue *toJS(ExecState *exec, NodeIteratorImpl *ni)
{
  return cacheDOMObject<NodeIteratorImpl, DOMNodeIterator>(exec, ni);
}


// -------------------------------------------------------------------------

const ClassInfo NodeFilterConstructor::info = { "NodeFilterConstructor", 0, &NodeFilterConstructorTable, 0 };
/*
@begin NodeFilterConstructorTable 17
  FILTER_ACCEPT		WebCore::NodeFilterImpl::FILTER_ACCEPT	DontDelete|ReadOnly
  FILTER_REJECT		WebCore::NodeFilterImpl::FILTER_REJECT	DontDelete|ReadOnly
  FILTER_SKIP		WebCore::NodeFilterImpl::FILTER_SKIP	DontDelete|ReadOnly
  SHOW_ALL		WebCore::NodeFilterImpl::SHOW_ALL	DontDelete|ReadOnly
  SHOW_ELEMENT		WebCore::NodeFilterImpl::SHOW_ELEMENT	DontDelete|ReadOnly
  SHOW_ATTRIBUTE	WebCore::NodeFilterImpl::SHOW_ATTRIBUTE	DontDelete|ReadOnly
  SHOW_TEXT		WebCore::NodeFilterImpl::SHOW_TEXT	DontDelete|ReadOnly
  SHOW_CDATA_SECTION	WebCore::NodeFilterImpl::SHOW_CDATA_SECTION	DontDelete|ReadOnly
  SHOW_ENTITY_REFERENCE	WebCore::NodeFilterImpl::SHOW_ENTITY_REFERENCE	DontDelete|ReadOnly
  SHOW_ENTITY		WebCore::NodeFilterImpl::SHOW_ENTITY	DontDelete|ReadOnly
  SHOW_PROCESSING_INSTRUCTION	WebCore::NodeFilterImpl::SHOW_PROCESSING_INSTRUCTION	DontDelete|ReadOnly
  SHOW_COMMENT		WebCore::NodeFilterImpl::SHOW_COMMENT	DontDelete|ReadOnly
  SHOW_DOCUMENT		WebCore::NodeFilterImpl::SHOW_DOCUMENT	DontDelete|ReadOnly
  SHOW_DOCUMENT_TYPE	WebCore::NodeFilterImpl::SHOW_DOCUMENT_TYPE	DontDelete|ReadOnly
  SHOW_DOCUMENT_FRAGMENT	WebCore::NodeFilterImpl::SHOW_DOCUMENT_FRAGMENT	DontDelete|ReadOnly
  SHOW_NOTATION		WebCore::NodeFilterImpl::SHOW_NOTATION	DontDelete|ReadOnly
@end
*/
bool NodeFilterConstructor::getOwnPropertySlot(ExecState *exec, const Identifier& propertyName, PropertySlot& slot)
{
  return getStaticValueSlot<NodeFilterConstructor, DOMObject>(exec, &NodeFilterConstructorTable, this, propertyName, slot);
}

JSValue *NodeFilterConstructor::getValueProperty(ExecState *, int token) const
{
  // We use the token as the value to return directly
  return jsNumber(token);
}

JSValue *getNodeFilterConstructor(ExecState *exec)
{
  return cacheGlobalObject<NodeFilterConstructor>(exec, "[[nodeFilter.constructor]]");
}

// -------------------------------------------------------------------------

const ClassInfo DOMNodeFilter::info = { "NodeFilter", 0, 0, 0 };
/*
@begin DOMNodeFilterProtoTable 1
  acceptNode	DOMNodeFilter::AcceptNode	DontDelete|Function 0
@end
*/
KJS_DEFINE_PROTOTYPE(DOMNodeFilterProto)
KJS_IMPLEMENT_PROTOFUNC(DOMNodeFilterProtoFunc)
KJS_IMPLEMENT_PROTOTYPE("DOMNodeFilter",DOMNodeFilterProto,DOMNodeFilterProtoFunc)

DOMNodeFilter::DOMNodeFilter(ExecState *exec, NodeFilterImpl *nf)
  : m_impl(nf) 
{
  setPrototype(DOMNodeFilterProto::self(exec));
}

DOMNodeFilter::~DOMNodeFilter()
{
  ScriptInterpreter::forgetDOMObject(m_impl.get());
}

void DOMNodeFilter::mark()
{
    m_impl->mark();
    DOMObject::mark();
}

JSValue *DOMNodeFilterProtoFunc::callAsFunction(ExecState *exec, JSObject *thisObj, const List &args)
{
  if (!thisObj->inherits(&KJS::DOMNodeFilter::info))
    return throwError(exec, TypeError);
  NodeFilterImpl &nodeFilter = *static_cast<DOMNodeFilter *>(thisObj)->impl();
  switch (id) {
    case DOMNodeFilter::AcceptNode:
      return jsNumber(nodeFilter.acceptNode(toNode(args[0])));
  }
  return jsUndefined();
}

JSValue *toJS(ExecState *exec, NodeFilterImpl *nf)
{
    return cacheDOMObject<NodeFilterImpl, DOMNodeFilter>(exec, nf);
}

NodeFilterImpl *toNodeFilter(JSValue *val)
{
    if (!val || !val->isObject(&DOMNodeFilter::info))
        return 0;
    return static_cast<DOMNodeFilter *>(val)->impl();
}

// -------------------------------------------------------------------------

const ClassInfo DOMTreeWalker::info = { "TreeWalker", 0, &DOMTreeWalkerTable, 0 };
/*
@begin DOMTreeWalkerTable 5
  root			DOMTreeWalker::Root		DontDelete|ReadOnly
  whatToShow		DOMTreeWalker::WhatToShow	DontDelete|ReadOnly
  filter		DOMTreeWalker::Filter		DontDelete|ReadOnly
  expandEntityReferences DOMTreeWalker::ExpandEntityReferences	DontDelete|ReadOnly
  currentNode		DOMTreeWalker::CurrentNode	DontDelete
@end
@begin DOMTreeWalkerProtoTable 7
  parentNode	DOMTreeWalker::ParentNode	DontDelete|Function 0
  firstChild	DOMTreeWalker::FirstChild	DontDelete|Function 0
  lastChild	DOMTreeWalker::LastChild	DontDelete|Function 0
  previousSibling DOMTreeWalker::PreviousSibling	DontDelete|Function 0
  nextSibling	DOMTreeWalker::NextSibling	DontDelete|Function 0
  previousNode	DOMTreeWalker::PreviousNode	DontDelete|Function 0
  nextNode	DOMTreeWalker::NextNode		DontDelete|Function 0
@end
*/
KJS_DEFINE_PROTOTYPE(DOMTreeWalkerProto)
KJS_IMPLEMENT_PROTOFUNC(DOMTreeWalkerProtoFunc)
KJS_IMPLEMENT_PROTOTYPE("DOMTreeWalker",DOMTreeWalkerProto,DOMTreeWalkerProtoFunc)

DOMTreeWalker::DOMTreeWalker(ExecState *exec, TreeWalkerImpl *tw)
  : m_impl(tw)
{
  setPrototype(DOMTreeWalkerProto::self(exec));
}

DOMTreeWalker::~DOMTreeWalker()
{
  ScriptInterpreter::forgetDOMObject(m_impl.get());
}

void DOMTreeWalker::mark()
{
    m_impl->filter()->mark();
    DOMObject::mark();
}

bool DOMTreeWalker::getOwnPropertySlot(ExecState *exec, const Identifier& propertyName, PropertySlot& slot)
{
  return getStaticValueSlot<DOMTreeWalker, DOMObject>(exec, &DOMTreeWalkerTable, this, propertyName, slot);
}

JSValue *DOMTreeWalker::getValueProperty(ExecState *exec, int token) const
{
  TreeWalkerImpl &tw = *m_impl;
  switch (token) {
  case Root:
    return toJS(exec,tw.root());
  case WhatToShow:
    return jsNumber(tw.whatToShow());
  case Filter:
    return toJS(exec,tw.filter());
  case ExpandEntityReferences:
    return jsBoolean(tw.expandEntityReferences());
  case CurrentNode:
    return toJS(exec,tw.currentNode());
  default:
    return 0;
  }
}

void DOMTreeWalker::put(ExecState *exec, const Identifier &propertyName,
                           JSValue *value, int attr)
{
  if (propertyName == "currentNode") {
    DOMExceptionTranslator exception(exec);
    m_impl->setCurrentNode(toNode(value), exception);
  }
  else
    JSObject::put(exec, propertyName, value, attr);
}

JSValue *DOMTreeWalkerProtoFunc::callAsFunction(ExecState *exec, JSObject *thisObj, const List &)
{
  if (!thisObj->inherits(&KJS::DOMTreeWalker::info))
    return throwError(exec, TypeError);
  TreeWalkerImpl &treeWalker = *static_cast<DOMTreeWalker *>(thisObj)->impl();
  switch (id) {
    case DOMTreeWalker::ParentNode:
      return toJS(exec,treeWalker.parentNode());
    case DOMTreeWalker::FirstChild:
      return toJS(exec,treeWalker.firstChild());
    case DOMTreeWalker::LastChild:
      return toJS(exec,treeWalker.lastChild());
    case DOMTreeWalker::PreviousSibling:
      return toJS(exec,treeWalker.previousSibling());
    case DOMTreeWalker::NextSibling:
      return toJS(exec,treeWalker.nextSibling());
    case DOMTreeWalker::PreviousNode:
      return toJS(exec,treeWalker.previousNode());
    case DOMTreeWalker::NextNode:
      return toJS(exec,treeWalker.nextNode());
  }
  return jsUndefined();
}

JSValue *toJS(ExecState *exec, TreeWalkerImpl *tw)
{
  return cacheDOMObject<TreeWalkerImpl, DOMTreeWalker>(exec, tw);
}

// -------------------------------------------------------------------------

JSNodeFilterCondition::JSNodeFilterCondition(JSObject * _filter)
    : filter( _filter )
{
}

void JSNodeFilterCondition::mark()
{
    filter->mark();
}

short JSNodeFilterCondition::acceptNode(NodeImpl* filterNode) const
{
    NodeImpl *node = filterNode;
    Frame *frame = node->getDocument()->frame();
    KJSProxyImpl *proxy = frame->jScript();
    if (proxy && filter->implementsCall()) {
        JSLock lock;
        ExecState *exec = proxy->interpreter()->globalExec();
        List args;
        args.append(toJS(exec, node));
        JSObject *obj = filter;
        JSValue *result = obj->call(exec, obj, args);
        return result->toInt32(exec);
    }

    return NodeFilterImpl::FILTER_REJECT;
}

} // namespace
