/* ANSI-C code produced by gperf version 2.7.2 */
/* Command-line: gperf -L ANSI-C -E -C -n -o -t -k '*' -NfindValue -Hhash_val -Wwordlist_value -D cssvalues.gperf  */
/* This file is automatically generated from cssvalues.in by makevalues, do not edit */
/* Copyright 1999 W. Bastian */
#include "cssvalues.h"
struct css_value {
    const char *name;
    int id;
};
/* maximum key range = 1909, duplicates = 1 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash_val (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909,  249, 1909, 1909,    0,    5,
        10,   15,   20,   35,   50,   55,   60,    0, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909,    0,  207,   20,
        27,  110,   25,  229,   29,    0,    0,   29,   20,   16,
        95,   35,  245,  255,   25,    5,    0,  135,    3,  160,
        98,  105,   34, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909, 1909,
      1909, 1909, 1909, 1909, 1909, 1909
    };
  register int hval = 0;

  switch (len)
    {
      default:
      case 21:
        hval += asso_values[(unsigned char)str[20]];
      case 20:
        hval += asso_values[(unsigned char)str[19]];
      case 19:
        hval += asso_values[(unsigned char)str[18]];
      case 18:
        hval += asso_values[(unsigned char)str[17]];
      case 17:
        hval += asso_values[(unsigned char)str[16]];
      case 16:
        hval += asso_values[(unsigned char)str[15]];
      case 15:
        hval += asso_values[(unsigned char)str[14]];
      case 14:
        hval += asso_values[(unsigned char)str[13]];
      case 13:
        hval += asso_values[(unsigned char)str[12]];
      case 12:
        hval += asso_values[(unsigned char)str[11]];
      case 11:
        hval += asso_values[(unsigned char)str[10]];
      case 10:
        hval += asso_values[(unsigned char)str[9]];
      case 9:
        hval += asso_values[(unsigned char)str[8]];
      case 8:
        hval += asso_values[(unsigned char)str[7]];
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

#ifdef __GNUC__
__inline
#endif
const struct css_value *
findValue (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 240,
      MIN_WORD_LENGTH = 3,
      MAX_WORD_LENGTH = 21,
      MIN_HASH_VALUE = 0,
      MAX_HASH_VALUE = 1908
    };

  static const struct css_value wordlist_value[] =
    {
      {"900", CSS_VAL_900},
      {"100", CSS_VAL_100},
      {"200", CSS_VAL_200},
      {"300", CSS_VAL_300},
      {"400", CSS_VAL_400},
      {"static", CSS_VAL_STATIC},
      {"start", CSS_VAL_START},
      {"500", CSS_VAL_500},
      {"italic", CSS_VAL_ITALIC},
      {"ltr", CSS_VAL_LTR},
      {"rtl", CSS_VAL_RTL},
      {"600", CSS_VAL_600},
      {"disc", CSS_VAL_DISC},
      {"700", CSS_VAL_700},
      {"800", CSS_VAL_800},
      {"small", CSS_VAL_SMALL},
      {"avoid", CSS_VAL_AVOID},
      {"thick", CSS_VAL_THICK},
      {"solid", CSS_VAL_SOLID},
      {"cross", CSS_VAL_CROSS},
      {"mix", CSS_VAL_MIX},
      {"thin", CSS_VAL_THIN},
      {"scroll", CSS_VAL_SCROLL},
      {"teal", CSS_VAL_TEAL},
      {"crosshair", CSS_VAL_CROSSHAIR},
      {"lime", CSS_VAL_LIME},
      {"icon", CSS_VAL_ICON},
      {"hand", CSS_VAL_HAND},
      {"katakana", CSS_VAL_KATAKANA},
      {"left", CSS_VAL_LEFT},
      {"wait", CSS_VAL_WAIT},
      {"red", CSS_VAL_RED},
      {"silver", CSS_VAL_SILVER},
      {"move", CSS_VAL_MOVE},
      {"serif", CSS_VAL_SERIF},
      {"hide", CSS_VAL_HIDE},
      {"olive", CSS_VAL_OLIVE},
      {"auto", CSS_VAL_AUTO},
      {"vertical", CSS_VAL_VERTICAL},
      {"stretch", CSS_VAL_STRETCH},
      {"normal", CSS_VAL_NORMAL},
      {"decimal", CSS_VAL_DECIMAL},
      {"circle", CSS_VAL_CIRCLE},
      {"smaller", CSS_VAL_SMALLER},
      {"dashed", CSS_VAL_DASHED},
      {"dotted", CSS_VAL_DOTTED},
      {"middle", CSS_VAL_MIDDLE},
      {"navy", CSS_VAL_NAVY},
      {"maroon", CSS_VAL_MAROON},
      {"text", CSS_VAL_TEXT},
      {"inset", CSS_VAL_INSET},
      {"fuchsia", CSS_VAL_FUCHSIA},
      {"loud", CSS_VAL_LOUD},
      {"show", CSS_VAL_SHOW},
      {"fantasy", CSS_VAL_FANTASY},
      {"end", CSS_VAL_END},
      {"invert", CSS_VAL_INVERT},
      {"inside", CSS_VAL_INSIDE},
      {"inherit", CSS_VAL_INHERIT},
      {"fixed", CSS_VAL_FIXED},
      {"level", CSS_VAL_LEVEL},
      {"relative", CSS_VAL_RELATIVE},
      {"justify", CSS_VAL_JUSTIFY},
      {"both", CSS_VAL_BOTH},
      {"horizontal", CSS_VAL_HORIZONTAL},
      {"black", CSS_VAL_BLACK},
      {"top", CSS_VAL_TOP},
      {"right", CSS_VAL_RIGHT},
      {"outset", CSS_VAL_OUTSET},
      {"hidden", CSS_VAL_HIDDEN},
      {"bold", CSS_VAL_BOLD},
      {"always", CSS_VAL_ALWAYS},
      {"bottom", CSS_VAL_BOTTOM},
      {"cursive", CSS_VAL_CURSIVE},
      {"white", CSS_VAL_WHITE},
      {"medium", CSS_VAL_MEDIUM},
      {"block", CSS_VAL_BLOCK},
      {"outside", CSS_VAL_OUTSIDE},
      {"default", CSS_VAL_DEFAULT},
      {"inline", CSS_VAL_INLINE},
      {"wider", CSS_VAL_WIDER},
      {"crop", CSS_VAL_CROP},
      {"portrait", CSS_VAL_PORTRAIT},
      {"none", CSS_VAL_NONE},
      {"compact", CSS_VAL_COMPACT},
      {"table", CSS_VAL_TABLE},
      {"box", CSS_VAL_BOX},
      {"armenian", CSS_VAL_ARMENIAN},
      {"visible", CSS_VAL_VISIBLE},
      {"sub", CSS_VAL_SUB},
      {"lower", CSS_VAL_LOWER},
      {"blink", CSS_VAL_BLINK},
      {"above", CSS_VAL_ABOVE},
      {"menu", CSS_VAL_MENU},
      {"scrollbar", CSS_VAL_SCROLLBAR},
      {"gray", CSS_VAL_GRAY},
      {"center", CSS_VAL_CENTER},
      {"infotext", CSS_VAL_INFOTEXT},
      {"hiragana", CSS_VAL_HIRAGANA},
      {"pre", CSS_VAL_PRE},
      {"large", CSS_VAL_LARGE},
      {"reverse", CSS_VAL_REVERSE},
      {"aqua", CSS_VAL_AQUA},
      {"ridge", CSS_VAL_RIDGE},
      {"caption", CSS_VAL_CAPTION},
      {"overline", CSS_VAL_OVERLINE},
      {"list-item", CSS_VAL_LIST_ITEM},
      {"help", CSS_VAL_HELP},
      {"x-small", CSS_VAL_X_SMALL},
      {"larger", CSS_VAL_LARGER},
      {"lighter", CSS_VAL_LIGHTER},
      {"higher", CSS_VAL_HIGHER},
      {"bolder", CSS_VAL_BOLDER},
      {"capitalize", CSS_VAL_CAPITALIZE},
      {"groove", CSS_VAL_GROOVE},
      {"yellow", CSS_VAL_YELLOW},
      {"collapse", CSS_VAL_COLLAPSE},
      {"threedface", CSS_VAL_THREEDFACE},
      {"single", CSS_VAL_SINGLE},
      {"grey", CSS_VAL_GREY},
      {"embed", CSS_VAL_EMBED},
      {"blue", CSS_VAL_BLUE},
      {"narrower", CSS_VAL_NARROWER},
      {"window", CSS_VAL_WINDOW},
      {"lowercase", CSS_VAL_LOWERCASE},
      {"repeat", CSS_VAL_REPEAT},
      {"katakana-iroha", CSS_VAL_KATAKANA_IROHA},
      {"orange", CSS_VAL_ORANGE},
      {"separate", CSS_VAL_SEPARATE},
      {"xx-small", CSS_VAL_XX_SMALL},
      {"pointer", CSS_VAL_POINTER},
      {"absolute", CSS_VAL_ABSOLUTE},
      {"sans-serif", CSS_VAL_SANS_SERIF},
      {"super", CSS_VAL_SUPER},
      {"landscape", CSS_VAL_LANDSCAPE},
      {"condensed", CSS_VAL_CONDENSED},
      {"activecaption", CSS_VAL_ACTIVECAPTION},
      {"square", CSS_VAL_SQUARE},
      {"below", CSS_VAL_BELOW},
      {"double", CSS_VAL_DOUBLE},
      {"s-resize", CSS_VAL_S_RESIZE},
      {"multiple", CSS_VAL_MULTIPLE},
      {"baseline", CSS_VAL_BASELINE},
      {"threedshadow", CSS_VAL_THREEDSHADOW},
      {"nowrap", CSS_VAL_NOWRAP},
      {"monospace", CSS_VAL_MONOSPACE},
      {"activeborder", CSS_VAL_ACTIVEBORDER},
      {"menutext", CSS_VAL_MENUTEXT},
      {"highlight", CSS_VAL_HIGHLIGHT},
      {"graytext", CSS_VAL_GRAYTEXT},
      {"green", CSS_VAL_GREEN},
      {"small-caps", CSS_VAL_SMALL_CAPS},
      {"run-in", CSS_VAL_RUN_IN},
      {"transparent", CSS_VAL_TRANSPARENT},
      {"captiontext", CSS_VAL_CAPTIONTEXT},
      {"underline", CSS_VAL_UNDERLINE},
      {"inactivecaption", CSS_VAL_INACTIVECAPTION},
      {"status-bar", CSS_VAL_STATUS_BAR},
      {"buttonface", CSS_VAL_BUTTONFACE},
      {"n-resize", CSS_VAL_N_RESIZE},
      {"threeddarkshadow", CSS_VAL_THREEDDARKSHADOW},
      {"hebrew", CSS_VAL_HEBREW},
      {"e-resize", CSS_VAL_E_RESIZE},
      {"se-resize", CSS_VAL_SE_RESIZE},
      {"windowframe", CSS_VAL_WINDOWFRAME},
      {"inactiveborder", CSS_VAL_INACTIVEBORDER},
      {"block-axis", CSS_VAL_BLOCK_AXIS},
      {"inline-axis", CSS_VAL_INLINE_AXIS},
      {"progress", CSS_VAL_PROGRESS},
      {"buttontext", CSS_VAL_BUTTONTEXT},
      {"windowtext", CSS_VAL_WINDOWTEXT},
      {"w-resize", CSS_VAL_W_RESIZE},
      {"sw-resize", CSS_VAL_SW_RESIZE},
      {"small-caption", CSS_VAL_SMALL_CAPTION},
      {"expanded", CSS_VAL_EXPANDED},
      {"lower-latin", CSS_VAL_LOWER_LATIN},
      {"hiragana-iroha", CSS_VAL_HIRAGANA_IROHA},
      {"georgian", CSS_VAL_GEORGIAN},
      {"buttonshadow", CSS_VAL_BUTTONSHADOW},
      {"x-large", CSS_VAL_X_LARGE},
      {"text-top", CSS_VAL_TEXT_TOP},
      {"ne-resize", CSS_VAL_NE_RESIZE},
      {"text-bottom", CSS_VAL_TEXT_BOTTOM},
      {"table-cell", CSS_VAL_TABLE_CELL},
      {"oblique", CSS_VAL_OBLIQUE},
      {"lower-roman", CSS_VAL_LOWER_ROMAN},
      {"highlighttext", CSS_VAL_HIGHLIGHTTEXT},
      {"purple", CSS_VAL_PURPLE},
      {"nw-resize", CSS_VAL_NW_RESIZE},
      {"background", CSS_VAL_BACKGROUND},
      {"table-row", CSS_VAL_TABLE_ROW},
      {"bidi-override", CSS_VAL_BIDI_OVERRIDE},
      {"xx-large", CSS_VAL_XX_LARGE},
      {"inactivecaptiontext", CSS_VAL_INACTIVECAPTIONTEXT},
      {"threedlightshadow", CSS_VAL_THREEDLIGHTSHADOW},
      {"repeat-x", CSS_VAL_REPEAT_X},
      {"repeat-y", CSS_VAL_REPEAT_Y},
      {"threedhighlight", CSS_VAL_THREEDHIGHLIGHT},
      {"no-repeat", CSS_VAL_NO_REPEAT},
      {"inline-block", CSS_VAL_INLINE_BLOCK},
      {"lower-alpha", CSS_VAL_LOWER_ALPHA},
      {"uppercase", CSS_VAL_UPPERCASE},
      {"semi-condensed", CSS_VAL_SEMI_CONDENSED},
      {"inline-table", CSS_VAL_INLINE_TABLE},
      {"table-column", CSS_VAL_TABLE_COLUMN},
      {"inline-box", CSS_VAL_INLINE_BOX},
      {"ultra-condensed", CSS_VAL_ULTRA_CONDENSED},
      {"line-through", CSS_VAL_LINE_THROUGH},
      {"infobackground", CSS_VAL_INFOBACKGROUND},
      {"close-quote", CSS_VAL_CLOSE_QUOTE},
      {"table-caption", CSS_VAL_TABLE_CAPTION},
      {"extra-condensed", CSS_VAL_EXTRA_CONDENSED},
      {"cjk-ideographic", CSS_VAL_CJK_IDEOGRAPHIC},
      {"buttonhighlight", CSS_VAL_BUTTONHIGHLIGHT},
      {"message-box", CSS_VAL_MESSAGE_BOX},
      {"-konq-auto", CSS_VAL__KONQ_AUTO},
      {"semi-expanded", CSS_VAL_SEMI_EXPANDED},
      {"lower-greek", CSS_VAL_LOWER_GREEK},
      {"-konq-normal", CSS_VAL__KONQ_NORMAL},
      {"appworkspace", CSS_VAL_APPWORKSPACE},
      {"-konq-text", CSS_VAL__KONQ_TEXT},
      {"upper-latin", CSS_VAL_UPPER_LATIN},
      {"ultra-expanded", CSS_VAL_ULTRA_EXPANDED},
      {"upper-roman", CSS_VAL_UPPER_ROMAN},
      {"extra-expanded", CSS_VAL_EXTRA_EXPANDED},
      {"open-quote", CSS_VAL_OPEN_QUOTE},
      {"-konq-center", CSS_VAL__KONQ_CENTER},
      {"-konq-body", CSS_VAL__KONQ_BODY},
      {"upper-alpha", CSS_VAL_UPPER_ALPHA},
      {"no-close-quote", CSS_VAL_NO_CLOSE_QUOTE},
      {"decimal-leading-zero", CSS_VAL_DECIMAL_LEADING_ZERO},
      {"-konq-nowrap", CSS_VAL__KONQ_NOWRAP},
      {"-konq-around-floats", CSS_VAL__KONQ_AROUND_FLOATS},
      {"no-open-quote", CSS_VAL_NO_OPEN_QUOTE},
      {"table-row-group", CSS_VAL_TABLE_ROW_GROUP},
      {"table-footer-group", CSS_VAL_TABLE_FOOTER_GROUP},
      {"table-header-group", CSS_VAL_TABLE_HEADER_GROUP},
      {"table-column-group", CSS_VAL_TABLE_COLUMN_GROUP},
      {"-konq-xxx-large", CSS_VAL__KONQ_XXX_LARGE},
      {"-konq-baseline-middle", CSS_VAL__KONQ_BASELINE_MIDDLE}
    };

  static const short lookup[] =
    {
         0,   -1,   -1,   -1,   -1,    1,   -1,   -1,
        -1,   -1,    2,   -1,   -1,   -1,   -1,    3,
        -1,   -1,   -1,   -1,    4,   -1,   -1,   -1,
        -1,    5,   -1,   -1,   -1,   -1,    6,   -1,
        -1,   -1,   -1,    7,   -1,   -1,   -1,   -1,
         8,   -1,   -1,   -1,   -1, -287, -231,   -2,
        -1,   -1,   11,   -1,   12,   -1,   -1,   13,
        -1,   -1,   -1,   -1,   14,   15,   -1,   -1,
        -1,   16,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   17,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   18,
        -1,   -1,   19,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   20,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   21,   22,   -1,   -1,
        -1,   -1,   23,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        24,   -1,   25,   -1,   -1,   -1,   26,   27,
        -1,   28,   -1,   29,   -1,   -1,   -1,   -1,
        30,   -1,   31,   32,   33,   34,   35,   -1,
        36,   -1,   37,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   38,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   39,   -1,   40,
        -1,   41,   -1,   42,   43,   -1,   44,   45,
        46,   -1,   -1,   47,   -1,   -1,   48,   -1,
        49,   -1,   50,   -1,   -1,   -1,   51,   -1,
        -1,   52,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   53,   54,   -1,
        55,   56,   -1,   -1,   -1,   57,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   58,   59,   -1,   -1,   60,
        -1,   -1,   -1,   -1,   61,   -1,   62,   63,
        -1,   64,   -1,   -1,   65,   -1,   -1,   -1,
        66,   -1,   -1,   67,   -1,   68,   -1,   -1,
        69,   70,   71,   -1,   -1,   72,   -1,   -1,
        -1,   -1,   73,   74,   -1,   -1,   -1,   -1,
        75,   -1,   -1,   -1,   -1,   -1,   -1,   76,
        77,   -1,   -1,   -1,   -1,   78,   -1,   -1,
        79,   -1,   80,   -1,   -1,   81,   -1,   -1,
        -1,   -1,   82,   -1,   -1,   -1,   -1,   83,
        84,   85,   -1,   -1,   86,   87,   -1,   -1,
        -1,   88,   -1,   89,   -1,   -1,   90,   91,
        -1,   -1,   -1,   92,   93,   94,   -1,   95,
        96,   -1,   -1,   97,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   98,   -1,   99,   -1,   -1,   -1,
       100,   -1,   -1,   -1,  101,   -1,  102,  103,
        -1,   -1,   -1,  104,   -1,   -1,  105,   -1,
       106,   -1,   -1,   -1,  107,   -1,   -1,   -1,
       108,  109,   -1,   -1,   -1,  110,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,  111,   -1,
       112,   -1,   -1,   -1,   -1,  113,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  114,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  115,   -1,   -1,   -1,   -1,  116,
       117,   -1,   -1,  118,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  119,  120,   -1,
       121,   -1,   -1,  122,   -1,  123,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
        -1,   -1,  125,  126,   -1,   -1,  127,  128,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  129,   -1,   -1,   -1,  130,   -1,
       131,   -1,   -1,   -1,   -1,   -1,   -1,  132,
       133,   -1,  134,   -1,  135,   -1,   -1,   -1,
       136,   -1,  137,   -1,  138,   -1,  139,   -1,
        -1,   -1,  140,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  141,  142,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  143,   -1,   -1,
       144,  145,  146,   -1,  147,  148,   -1,  149,
        -1,  150,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,  151,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,  152,
       153,   -1,   -1,  154,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,  155,   -1,   -1,   -1,   -1,   -1,  156,
        -1,   -1,  157,  158,  159,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,  160,   -1,
        -1,  161,   -1,  162,   -1,   -1,   -1,   -1,
       163,   -1,   -1,   -1,   -1,  164,   -1,   -1,
        -1,  165,   -1,   -1,   -1,   -1,   -1,  166,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       167,   -1,   -1,   -1,   -1,   -1,   -1,  168,
       169,   -1,   -1,   -1,   -1,  170,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  171,   -1,   -1,
        -1,   -1,  172,   -1,   -1,   -1,   -1,   -1,
        -1,  173,   -1,   -1,   -1,   -1,   -1,   -1,
       174,   -1,  175,   -1,  176,   -1,   -1,   -1,
        -1,   -1,   -1,  177,   -1,   -1,   -1,   -1,
       178,   -1,   -1,  179,   -1,   -1,   -1,   -1,
        -1,  180,  181,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,  182,   -1,
        -1,   -1,   -1,   -1,  183,   -1,   -1,   -1,
        -1,   -1,  184,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  185,   -1,   -1,  186,   -1,   -1,
        -1,   -1,   -1,   -1,  187,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,  188,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  189,   -1,   -1,   -1,  190,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  191,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  192,   -1,  193,
        -1,   -1,   -1,  194,   -1,  195,   -1,   -1,
        -1,   -1,   -1,   -1,  196,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  197,   -1,   -1,  198,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       199,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  200,   -1,  201,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       202,   -1,  203,  204,   -1,  205,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,  206,   -1,   -1,  207,  208,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,  209,   -1,
        -1,   -1,   -1,   -1,   -1,  210,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,  211,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  212,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  213,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       214,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  215,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,  216,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,  217,  218,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,  219,
       220,   -1,   -1,   -1,  221,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  222,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,  223,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,  224,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  225,   -1,   -1,
       226,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,  227,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,  228,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,  229,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       230,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       231,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,  232,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
       233,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,  234,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,  235,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,  236,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,  237,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,  238,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
        -1,   -1,   -1,   -1,  239
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash_val (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist_value[index].name;

              if (*str == *s && !strcmp (str + 1, s + 1))
                return &wordlist_value[index];
            }
          else if (index < -TOTAL_KEYWORDS)
            {
              register int offset = - 1 - TOTAL_KEYWORDS - index;
              register const struct css_value *wordptr = &wordlist_value[TOTAL_KEYWORDS + lookup[offset]];
              register const struct css_value *wordendptr = wordptr + -lookup[offset + 1];

              while (wordptr < wordendptr)
                {
                  register const char *s = wordptr->name;

                  if (*str == *s && !strcmp (str + 1, s + 1))
                    return wordptr;
                  wordptr++;
                }
            }
        }
    }
  return 0;
}
static const char * const valueList[] = {
"",
"inherit", 
"none", 
"hidden", 
"dotted", 
"dashed", 
"double", 
"solid", 
"outset", 
"inset", 
"groove", 
"ridge", 
"caption", 
"icon", 
"menu", 
"message-box", 
"small-caption", 
"status-bar", 
"italic", 
"oblique", 
"small-caps", 
"normal", 
"bold", 
"bolder", 
"lighter", 
"100", 
"200", 
"300", 
"400", 
"500", 
"600", 
"700", 
"800", 
"900", 
"xx-small", 
"x-small", 
"small", 
"medium", 
"large", 
"x-large", 
"xx-large", 
"-konq-xxx-large", 
"smaller", 
"larger", 
"wider", 
"narrower", 
"ultra-condensed", 
"extra-condensed", 
"condensed", 
"semi-condensed", 
"semi-expanded", 
"expanded", 
"extra-expanded", 
"ultra-expanded", 
"serif", 
"sans-serif", 
"cursive", 
"fantasy", 
"monospace", 
"-konq-body", 
"transparent", 
"aqua", 
"black", 
"blue", 
"fuchsia", 
"gray", 
"green", 
"lime", 
"maroon", 
"navy", 
"olive", 
"orange", 
"purple", 
"red", 
"silver", 
"teal", 
"white", 
"yellow", 
"activeborder", 
"activecaption", 
"appworkspace", 
"background", 
"buttonface", 
"buttonhighlight", 
"buttonshadow", 
"buttontext", 
"captiontext", 
"graytext", 
"highlight", 
"highlighttext", 
"inactiveborder", 
"inactivecaption", 
"inactivecaptiontext", 
"infobackground", 
"infotext", 
"menutext", 
"scrollbar", 
"threeddarkshadow", 
"threedface", 
"threedhighlight", 
"threedlightshadow", 
"threedshadow", 
"window", 
"windowframe", 
"windowtext", 
"grey", 
"-konq-text", 
"repeat", 
"repeat-x", 
"repeat-y", 
"no-repeat", 
"baseline", 
"middle", 
"sub", 
"super", 
"text-top", 
"text-bottom", 
"top", 
"bottom", 
"-konq-baseline-middle", 
"-konq-auto", 
"left", 
"right", 
"center", 
"justify", 
"-konq-center", 
"outside", 
"inside", 
"disc", 
"circle", 
"square", 
"decimal", 
"decimal-leading-zero", 
"lower-roman", 
"upper-roman", 
"lower-greek", 
"lower-alpha", 
"lower-latin", 
"upper-alpha", 
"upper-latin", 
"hebrew", 
"armenian", 
"georgian", 
"cjk-ideographic", 
"hiragana", 
"katakana", 
"hiragana-iroha", 
"katakana-iroha", 
"inline", 
"block", 
"list-item", 
"run-in", 
"compact", 
"inline-block", 
"table", 
"inline-table", 
"table-row-group", 
"table-header-group", 
"table-footer-group", 
"table-row", 
"table-column-group", 
"table-column", 
"table-cell", 
"table-caption", 
"box", 
"inline-box", 
"auto", 
"crosshair", 
"default", 
"pointer", 
"progress", 
"move", 
"e-resize", 
"ne-resize", 
"nw-resize", 
"n-resize", 
"se-resize", 
"sw-resize", 
"s-resize", 
"w-resize", 
"text", 
"wait", 
"help", 
"ltr", 
"rtl", 
"capitalize", 
"uppercase", 
"lowercase", 
"visible", 
"collapse", 
"above", 
"absolute", 
"always", 
"avoid", 
"below", 
"bidi-override", 
"blink", 
"both", 
"close-quote", 
"crop", 
"cross", 
"embed", 
"fixed", 
"hand", 
"hide", 
"higher", 
"invert", 
"landscape", 
"level", 
"line-through", 
"loud", 
"lower", 
"mix", 
"no-close-quote", 
"no-open-quote", 
"nowrap", 
"open-quote", 
"overline", 
"portrait", 
"pre", 
"relative", 
"scroll", 
"separate", 
"show", 
"static", 
"thick", 
"thin", 
"underline", 
"-konq-nowrap", 
"-konq-normal", 
"-konq-around-floats", 
"stretch", 
"start", 
"end", 
"reverse", 
"horizontal", 
"vertical", 
"inline-axis", 
"block-axis", 
"single", 
"multiple", 
    0
};
DOMString getValueName(unsigned short id)
{
    if(id >= CSS_VAL_TOTAL || id == 0)
      return DOMString();
    else
      return DOMString(valueList[id]);
};

