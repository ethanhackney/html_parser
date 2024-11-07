#include "parser.h"

parser::~parser()
{
        for (auto r : _roots)
                delete r;
}

node* parser::get_root(size_t i)
{
        return _roots.at(i);
}

size_t parser::n_roots(void)
{
        return _roots.size();
}

parser::parser(lexer& lex)
        : _lex {lex}
{
        _lex.next();
}

void parser::parse(void)
{
        while (_lex.type() != TOK_EOF)
                _roots.push_back(do_parse());
}

node* parser::do_parse(void)
{
        if (_lex.type() == TOK_LT) {
                return parse_tag();
        } else {
                auto n = new text_node{_lex.lex().c_str()[0]};
                _lex.skip(TOK_CHAR);
                return n;
        }
}

node* parser::parse_tag(void)
{
        _lex.skip(TOK_LT);
        auto type = _lex.type();

        _lex.skip(type);

        node* n;
	if (type == TOK_ABBR_TAG) {
		n = new abbr_node{};
	} else 	if (type == TOK_A_TAG) {
		n = new a_node{};
	} else 	if (type == TOK_BODY_TAG) {
		n = new body_node{};
	} else 	if (type == TOK_BOLD_TAG) {
		n = new bold_node{};
	} else 	if (type == TOK_DIV_TAG) {
		n = new div_node{};
	} else 	if (type == TOK_HTML_TAG) {
		n = new html_node{};
	} else 	if (type == TOK_P_TAG) {
		n = new p_node{};
	} else 	if (type == TOK_TABLE_TAG) {
		n = new table_node{};
	} else 	if (type == TOK_AREA_TAG) {
		n = new area_node{};
	} else 	if (type == TOK_ARTICLE_TAG) {
		n = new article_node{};
	} else 	if (type == TOK_ASIDE_TAG) {
		n = new aside_node{};
	} else 	if (type == TOK_AUDIO_TAG) {
		n = new audio_node{};
	} else 	if (type == TOK_B_TAG) {
		n = new b_node{};
	} else 	if (type == TOK_BASE_TAG) {
		n = new base_node{};
	} else 	if (type == TOK_BDI_TAG) {
		n = new bdi_node{};
	} else 	if (type == TOK_BDO_TAG) {
		n = new bdo_node{};
	} else 	if (type == TOK_BLOCKQUOTE_TAG) {
		n = new blockquote_node{};
	} else 	if (type == TOK_BR_TAG) {
		n = new br_node{};
	} else 	if (type == TOK_BUTTON_TAG) {
		n = new button_node{};
	} else 	if (type == TOK_CANVAS_TAG) {
		n = new canvas_node{};
	} else 	if (type == TOK_CAPTION_TAG) {
		n = new caption_node{};
	} else 	if (type == TOK_CITE_TAG) {
		n = new cite_node{};
	} else 	if (type == TOK_CODE_TAG) {
		n = new code_node{};
	} else 	if (type == TOK_COL_TAG) {
		n = new col_node{};
	} else 	if (type == TOK_COLGROUP_TAG) {
		n = new colgroup_node{};
	} else 	if (type == TOK_DATA_TAG) {
		n = new data_node{};
	} else 	if (type == TOK_DATALIST_TAG) {
		n = new datalist_node{};
	} else 	if (type == TOK_DD_TAG) {
		n = new dd_node{};
	} else 	if (type == TOK_DEL_TAG) {
		n = new del_node{};
	} else 	if (type == TOK_DETAILS_TAG) {
		n = new details_node{};
	} else 	if (type == TOK_DFN_TAG) {
		n = new dfn_node{};
	} else 	if (type == TOK_DIALOG_TAG) {
		n = new dialog_node{};
	} else 	if (type == TOK_DL_TAG) {
		n = new dl_node{};
	} else 	if (type == TOK_DT_TAG) {
		n = new dt_node{};
	} else 	if (type == TOK_EM_TAG) {
		n = new em_node{};
	} else 	if (type == TOK_EMBED_TAG) {
		n = new embed_node{};
	} else 	if (type == TOK_FIELDSET_TAG) {
		n = new fieldset_node{};
	} else 	if (type == TOK_FIGCAPTION_TAG) {
		n = new figcaption_node{};
	} else 	if (type == TOK_FIGURE_TAG) {
		n = new figure_node{};
	} else 	if (type == TOK_FOOTER_TAG) {
		n = new footer_node{};
	} else 	if (type == TOK_FORM_TAG) {
		n = new form_node{};
	} else 	if (type == TOK_H1_TAG) {
		n = new h1_node{};
	} else 	if (type == TOK_HEAD_TAG) {
		n = new head_node{};
	} else 	if (type == TOK_HEADER_TAG) {
		n = new header_node{};
	} else 	if (type == TOK_HGROUP_TAG) {
		n = new hgroup_node{};
	} else 	if (type == TOK_HR_TAG) {
		n = new hr_node{};
	} else 	if (type == TOK_I_TAG) {
		n = new i_node{};
	} else 	if (type == TOK_IFRAME_TAG) {
		n = new iframe_node{};
	} else 	if (type == TOK_IMG_TAG) {
		n = new img_node{};
	} else 	if (type == TOK_INPUT_TAG) {
		n = new input_node{};
	} else 	if (type == TOK_INS_TAG) {
		n = new ins_node{};
	} else 	if (type == TOK_KBD_TAG) {
		n = new kbd_node{};
	} else 	if (type == TOK_LABEL_TAG) {
		n = new label_node{};
	} else 	if (type == TOK_LEGEND_TAG) {
		n = new legend_node{};
	} else 	if (type == TOK_LI_TAG) {
		n = new li_node{};
	} else 	if (type == TOK_LINK_TAG) {
		n = new link_node{};
	} else 	if (type == TOK_MAIN_TAG) {
		n = new main_node{};
	} else 	if (type == TOK_MAP_TAG) {
		n = new map_node{};
	} else 	if (type == TOK_MARK_TAG) {
		n = new mark_node{};
	} else 	if (type == TOK_MENU_TAG) {
		n = new menu_node{};
	} else 	if (type == TOK_META_TAG) {
		n = new meta_node{};
	} else 	if (type == TOK_METER_TAG) {
		n = new meter_node{};
	} else 	if (type == TOK_NAV_TAG) {
		n = new nav_node{};
	} else 	if (type == TOK_NOSCRIPT_TAG) {
		n = new noscript_node{};
	} else 	if (type == TOK_OBJECT_TAG) {
		n = new object_node{};
	} else 	if (type == TOK_OL_TAG) {
		n = new ol_node{};
	} else 	if (type == TOK_OPTGROUP_TAG) {
		n = new optgroup_node{};
	} else 	if (type == TOK_OPTION_TAG) {
		n = new option_node{};
	} else 	if (type == TOK_OUTPUT_TAG) {
		n = new output_node{};
	} else 	if (type == TOK_PICTURE_TAG) {
		n = new picture_node{};
	} else 	if (type == TOK_PRE_TAG) {
		n = new pre_node{};
	} else 	if (type == TOK_PROGRESS_TAG) {
		n = new progress_node{};
	} else 	if (type == TOK_Q_TAG) {
		n = new q_node{};
	} else 	if (type == TOK_RP_TAG) {
		n = new rp_node{};
	} else 	if (type == TOK_RT_TAG) {
		n = new rt_node{};
	} else 	if (type == TOK_RUBY_TAG) {
		n = new ruby_node{};
	} else 	if (type == TOK_S_TAG) {
		n = new s_node{};
	} else 	if (type == TOK_SAMP_TAG) {
		n = new samp_node{};
	} else 	if (type == TOK_SCRIPT_TAG) {
		n = new script_node{};
	} else 	if (type == TOK_SEARCH_TAG) {
		n = new search_node{};
	} else 	if (type == TOK_SECTION_TAG) {
		n = new section_node{};
	} else 	if (type == TOK_SELECT_TAG) {
		n = new select_node{};
	} else 	if (type == TOK_SLOT_TAG) {
		n = new slot_node{};
	} else 	if (type == TOK_SMALL_TAG) {
		n = new small_node{};
	} else 	if (type == TOK_SOURCE_TAG) {
		n = new source_node{};
	} else 	if (type == TOK_SPAN_TAG) {
		n = new span_node{};
	} else 	if (type == TOK_STRONG_TAG) {
		n = new strong_node{};
	} else 	if (type == TOK_STYLE_TAG) {
		n = new style_node{};
	} else 	if (type == TOK_SUB_TAG) {
		n = new sub_node{};
	} else 	if (type == TOK_SUMMARY_TAG) {
		n = new summary_node{};
	} else 	if (type == TOK_SUP_TAG) {
		n = new sup_node{};
	} else 	if (type == TOK_TBODY_TAG) {
		n = new tbody_node{};
	} else 	if (type == TOK_TD_TAG) {
		n = new td_node{};
	} else 	if (type == TOK_TEMPLATE_TAG) {
		n = new template_node{};
	} else 	if (type == TOK_TEXTAREA_TAG) {
		n = new textarea_node{};
	} else 	if (type == TOK_TFOOT_TAG) {
		n = new tfoot_node{};
	} else 	if (type == TOK_TH_TAG) {
		n = new th_node{};
	} else 	if (type == TOK_THEAD_TAG) {
		n = new thead_node{};
	} else 	if (type == TOK_TIME_TAG) {
		n = new time_node{};
	} else 	if (type == TOK_TITLE_TAG) {
		n = new title_node{};
	} else 	if (type == TOK_TR_TAG) {
		n = new tr_node{};
	} else 	if (type == TOK_TRACK_TAG) {
		n = new track_node{};
	} else 	if (type == TOK_U_TAG) {
		n = new u_node{};
	} else 	if (type == TOK_UL_TAG) {
		n = new ul_node{};
	} else 	if (type == TOK_VAR_TAG) {
		n = new var_node{};
	} else 	if (type == TOK_VIDEO_TAG) {
		n = new video_node{};
	} else 	if (type == TOK_WBR_TAG) {
		n = new wbr_node{};
	} else         {
                errno = EINVAL;
                err(EX_USAGE, "invalid tagname: %s", token{type}.name().c_str());
        }

        while (_lex.type() != TOK_GT) {
                auto attr = _lex.lex();
                _lex.skip(_lex.type());
                n->set_attr(attr, "on");
                if (_lex.type() == TOK_EQ) {
                        _lex.skip(TOK_EQ);
                        auto v = _lex.lex();
                        _lex.skip(_lex.type());
                        n->set_attr(attr, v);
                }
        }
        _lex.skip(TOK_GT);

        for (;;) {
                if (_lex.type() == TOK_LT) {
                        if (_lex.peek().type() == TOK_SLASH)
                                break;
                }
                n->add_kid(do_parse());
        }

        _lex.skip(TOK_LT);
        _lex.skip(TOK_SLASH);
        _lex.skip(type);
        _lex.skip(TOK_GT);
        return n;
}
