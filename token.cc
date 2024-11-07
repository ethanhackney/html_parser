#include "token.h"

token::token(void)
{
}

static void typeok(int type)
{
        switch (type) {
        case TOK_ERR:
        case TOK_EOF:
        case TOK_LT:
        case TOK_HREF:
        case TOK_EQ:
        case TOK_STR:
        case TOK_GT:
        case TOK_CHAR:
        case TOK_SLASH:
        case TOK_DOWNLOAD:
        case TOK_HREFLANG:
        case TOK_MEDIA:
        case TOK_PING:
        case TOK_REFERRER_POLICY:
        case TOK_REL:
        case TOK_TARGET:
        case TOK_TYPE:
        case TOK_XMLNS:
        case TOK_ACCESS_KEY:
        case TOK_LANG:
        case TOK_AUTO_CAPITALIZE:
	case TOK_ABBR_TAG:
	case TOK_A_TAG:
	case TOK_BODY_TAG:
	case TOK_BOLD_TAG:
	case TOK_DIV_TAG:
	case TOK_HTML_TAG:
	case TOK_P_TAG:
	case TOK_TABLE_TAG:
	case TOK_AREA_TAG:
	case TOK_ARTICLE_TAG:
	case TOK_ASIDE_TAG:
	case TOK_AUDIO_TAG:
	case TOK_B_TAG:
	case TOK_BASE_TAG:
	case TOK_BDI_TAG:
	case TOK_BDO_TAG:
	case TOK_BLOCKQUOTE_TAG:
	case TOK_BR_TAG:
	case TOK_BUTTON_TAG:
	case TOK_CANVAS_TAG:
	case TOK_CAPTION_TAG:
	case TOK_CITE_TAG:
	case TOK_CODE_TAG:
	case TOK_COL_TAG:
	case TOK_COLGROUP_TAG:
	case TOK_DATA_TAG:
	case TOK_DATALIST_TAG:
	case TOK_DD_TAG:
	case TOK_DEL_TAG:
	case TOK_DETAILS_TAG:
	case TOK_DFN_TAG:
	case TOK_DIALOG_TAG:
	case TOK_DL_TAG:
	case TOK_DT_TAG:
	case TOK_EM_TAG:
	case TOK_EMBED_TAG:
	case TOK_FIELDSET_TAG:
	case TOK_FIGCAPTION_TAG:
	case TOK_FIGURE_TAG:
	case TOK_FOOTER_TAG:
	case TOK_FORM_TAG:
	case TOK_H1_TAG:
	case TOK_HEAD_TAG:
	case TOK_HEADER_TAG:
	case TOK_HGROUP_TAG:
	case TOK_HR_TAG:
	case TOK_I_TAG:
	case TOK_IFRAME_TAG:
	case TOK_IMG_TAG:
	case TOK_INPUT_TAG:
	case TOK_INS_TAG:
	case TOK_KBD_TAG:
	case TOK_LABEL_TAG:
	case TOK_LEGEND_TAG:
	case TOK_LI_TAG:
	case TOK_LINK_TAG:
	case TOK_MAIN_TAG:
	case TOK_MAP_TAG:
	case TOK_MARK_TAG:
	case TOK_MENU_TAG:
	case TOK_META_TAG:
	case TOK_METER_TAG:
	case TOK_NAV_TAG:
	case TOK_NOSCRIPT_TAG:
	case TOK_OBJECT_TAG:
	case TOK_OL_TAG:
	case TOK_OPTGROUP_TAG:
	case TOK_OPTION_TAG:
	case TOK_OUTPUT_TAG:
	case TOK_PICTURE_TAG:
	case TOK_PRE_TAG:
	case TOK_PROGRESS_TAG:
	case TOK_Q_TAG:
	case TOK_RP_TAG:
	case TOK_RT_TAG:
	case TOK_RUBY_TAG:
	case TOK_S_TAG:
	case TOK_SAMP_TAG:
	case TOK_SCRIPT_TAG:
	case TOK_SEARCH_TAG:
	case TOK_SECTION_TAG:
	case TOK_SELECT_TAG:
	case TOK_SLOT_TAG:
	case TOK_SMALL_TAG:
	case TOK_SOURCE_TAG:
	case TOK_SPAN_TAG:
	case TOK_STRONG_TAG:
	case TOK_STYLE_TAG:
	case TOK_SUB_TAG:
	case TOK_SUMMARY_TAG:
	case TOK_SUP_TAG:
	case TOK_TBODY_TAG:
	case TOK_TD_TAG:
	case TOK_TEMPLATE_TAG:
	case TOK_TEXTAREA_TAG:
	case TOK_TFOOT_TAG:
	case TOK_TH_TAG:
	case TOK_THEAD_TAG:
	case TOK_TIME_TAG:
	case TOK_TITLE_TAG:
	case TOK_TR_TAG:
	case TOK_TRACK_TAG:
	case TOK_U_TAG:
	case TOK_UL_TAG:
	case TOK_VAR_TAG:
	case TOK_VIDEO_TAG:
	case TOK_WBR_TAG:
                break;
        default:
                errno = EINVAL;
                err(EX_USAGE, "bad token type: %d", type);
        }
}

token::token(int type)
        : _type {type}
{
        typeok(_type);
}

token::token(int type, int c)
        : _type {type}
{
        typeok(_type);
        _lex += c;
}

token::token(int type, const std::string& lex)
        : _lex {lex},
        _type {type}
{
        typeok(_type);
}

int token::type(void) const
{
        return _type;
}

std::string token::lex(void) const
{
        return _lex;
}

std::string token::name(void) const
{
        std::array<std::string,TOK_COUNT> names {
                "TOK_ERR",
                "TOK_EOF",
                "TOK_LT",
                "TOK_HREF",
                "TOK_EQ",
                "TOK_STR",
                "TOK_GT",
                "TOK_CHAR",
                "TOK_SLASH",
                "TOK_DOWNLOAD",
                "TOK_HREFLANG",
                "TOK_MEDIA",
                "TOK_PING",
                "TOK_REFERRER_POLICY",
                "TOK_REL",
                "TOK_TARGET",
                "TOK_TYPE",
                "TOK_XMLNS",
                "TOK_ACCESS_KEY",
                "TOK_LANG",
                "TOK_AUTO_CAPITALIZE",
		"TOK_ABBR_TAG",
		"TOK_A_TAG",
		"TOK_BODY_TAG",
		"TOK_BOLD_TAG",
		"TOK_DIV_TAG",
		"TOK_HTML_TAG",
		"TOK_P_TAG",
		"TOK_TABLE_TAG",
		"TOK_AREA_TAG",
		"TOK_ARTICLE_TAG",
		"TOK_ASIDE_TAG",
		"TOK_AUDIO_TAG",
		"TOK_B_TAG",
		"TOK_BASE_TAG",
		"TOK_BDI_TAG",
		"TOK_BDO_TAG",
		"TOK_BLOCKQUOTE_TAG",
		"TOK_BR_TAG",
		"TOK_BUTTON_TAG",
		"TOK_CANVAS_TAG",
		"TOK_CAPTION_TAG",
		"TOK_CITE_TAG",
		"TOK_CODE_TAG",
		"TOK_COL_TAG",
		"TOK_COLGROUP_TAG",
		"TOK_DATA_TAG",
		"TOK_DATALIST_TAG",
		"TOK_DD_TAG",
		"TOK_DEL_TAG",
		"TOK_DETAILS_TAG",
		"TOK_DFN_TAG",
		"TOK_DIALOG_TAG",
		"TOK_DL_TAG",
		"TOK_DT_TAG",
		"TOK_EM_TAG",
		"TOK_EMBED_TAG",
		"TOK_FIELDSET_TAG",
		"TOK_FIGCAPTION_TAG",
		"TOK_FIGURE_TAG",
		"TOK_FOOTER_TAG",
		"TOK_FORM_TAG",
		"TOK_H1_TAG",
		"TOK_HEAD_TAG",
		"TOK_HEADER_TAG",
		"TOK_HGROUP_TAG",
		"TOK_HR_TAG",
		"TOK_I_TAG",
		"TOK_IFRAME_TAG",
		"TOK_IMG_TAG",
		"TOK_INPUT_TAG",
		"TOK_INS_TAG",
		"TOK_KBD_TAG",
		"TOK_LABEL_TAG",
		"TOK_LEGEND_TAG",
		"TOK_LI_TAG",
		"TOK_LINK_TAG",
		"TOK_MAIN_TAG",
		"TOK_MAP_TAG",
		"TOK_MARK_TAG",
		"TOK_MENU_TAG",
		"TOK_META_TAG",
		"TOK_METER_TAG",
		"TOK_NAV_TAG",
		"TOK_NOSCRIPT_TAG",
		"TOK_OBJECT_TAG",
		"TOK_OL_TAG",
		"TOK_OPTGROUP_TAG",
		"TOK_OPTION_TAG",
		"TOK_OUTPUT_TAG",
		"TOK_PICTURE_TAG",
		"TOK_PRE_TAG",
		"TOK_PROGRESS_TAG",
		"TOK_Q_TAG",
		"TOK_RP_TAG",
		"TOK_RT_TAG",
		"TOK_RUBY_TAG",
		"TOK_S_TAG",
		"TOK_SAMP_TAG",
		"TOK_SCRIPT_TAG",
		"TOK_SEARCH_TAG",
		"TOK_SECTION_TAG",
		"TOK_SELECT_TAG",
		"TOK_SLOT_TAG",
		"TOK_SMALL_TAG",
		"TOK_SOURCE_TAG",
		"TOK_SPAN_TAG",
		"TOK_STRONG_TAG",
		"TOK_STYLE_TAG",
		"TOK_SUB_TAG",
		"TOK_SUMMARY_TAG",
		"TOK_SUP_TAG",
		"TOK_TBODY_TAG",
		"TOK_TD_TAG",
		"TOK_TEMPLATE_TAG",
		"TOK_TEXTAREA_TAG",
		"TOK_TFOOT_TAG",
		"TOK_TH_TAG",
		"TOK_THEAD_TAG",
		"TOK_TIME_TAG",
		"TOK_TITLE_TAG",
		"TOK_TR_TAG",
		"TOK_TRACK_TAG",
		"TOK_U_TAG",
		"TOK_UL_TAG",
		"TOK_VAR_TAG",
		"TOK_VIDEO_TAG",
		"TOK_WBR_TAG",
        };
        return names.at(_type);
}
