#ifndef PARSER_H
#define PARSER_H

#include "abbr_node.h"
#include "a_node.h"
#include "body_node.h"
#include "bold_node.h"
#include "div_node.h"
#include "html_node.h"
#include "p_node.h"
#include "table_node.h"
#include "area_node.h"
#include "article_node.h"
#include "aside_node.h"
#include "audio_node.h"
#include "b_node.h"
#include "base_node.h"
#include "bdi_node.h"
#include "bdo_node.h"
#include "blockquote_node.h"
#include "br_node.h"
#include "button_node.h"
#include "canvas_node.h"
#include "caption_node.h"
#include "cite_node.h"
#include "code_node.h"
#include "col_node.h"
#include "colgroup_node.h"
#include "data_node.h"
#include "datalist_node.h"
#include "dd_node.h"
#include "del_node.h"
#include "details_node.h"
#include "dfn_node.h"
#include "dialog_node.h"
#include "dl_node.h"
#include "dt_node.h"
#include "em_node.h"
#include "embed_node.h"
#include "fieldset_node.h"
#include "figcaption_node.h"
#include "figure_node.h"
#include "footer_node.h"
#include "form_node.h"
#include "h1_node.h"
#include "head_node.h"
#include "header_node.h"
#include "hgroup_node.h"
#include "hr_node.h"
#include "i_node.h"
#include "iframe_node.h"
#include "img_node.h"
#include "input_node.h"
#include "ins_node.h"
#include "kbd_node.h"
#include "label_node.h"
#include "legend_node.h"
#include "li_node.h"
#include "link_node.h"
#include "main_node.h"
#include "map_node.h"
#include "mark_node.h"
#include "menu_node.h"
#include "meta_node.h"
#include "meter_node.h"
#include "nav_node.h"
#include "noscript_node.h"
#include "object_node.h"
#include "ol_node.h"
#include "optgroup_node.h"
#include "option_node.h"
#include "output_node.h"
#include "picture_node.h"
#include "pre_node.h"
#include "progress_node.h"
#include "q_node.h"
#include "rp_node.h"
#include "rt_node.h"
#include "ruby_node.h"
#include "s_node.h"
#include "samp_node.h"
#include "script_node.h"
#include "search_node.h"
#include "section_node.h"
#include "select_node.h"
#include "slot_node.h"
#include "small_node.h"
#include "source_node.h"
#include "span_node.h"
#include "strong_node.h"
#include "style_node.h"
#include "sub_node.h"
#include "summary_node.h"
#include "sup_node.h"
#include "tbody_node.h"
#include "td_node.h"
#include "template_node.h"
#include "textarea_node.h"
#include "tfoot_node.h"
#include "th_node.h"
#include "thead_node.h"
#include "time_node.h"
#include "title_node.h"
#include "tr_node.h"
#include "track_node.h"
#include "u_node.h"
#include "ul_node.h"
#include "var_node.h"
#include "video_node.h"
#include "wbr_node.h"
#include "text_node.h"
#include "lexer.h"
#include <vector>

class parser {
private:
        std::vector<node*> _roots;
        lexer& _lex;

        node* do_parse(void);
        node* parse_tag(void);
public:
        parser(lexer& lex);
        void parse(void);
        node* get_root(size_t i);
        size_t n_roots(void);
        ~parser();
};

#endif
