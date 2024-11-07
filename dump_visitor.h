#ifndef DUMP_VISITOR_H
#define DUMP_VISITOR_H

#include "text_node.h"
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

#include "node_visitor.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class dump_visitor : public node_visitor {
private:
        int _indent {0};

        void dump_attrs(std::unordered_map<std::string,std::string>& attrs);
        void dump_kids(std::vector<node*>& kids);
        void dump_internal_node(const std::string& name, internal_node* n);
        void indent(int space);
public:
        virtual void visit(text_node* n);
	virtual void visit(abbr_node* n);
	virtual void visit(a_node* n);
	virtual void visit(body_node* n);
	virtual void visit(bold_node* n);
	virtual void visit(div_node* n);
	virtual void visit(html_node* n);
	virtual void visit(p_node* n);
	virtual void visit(table_node* n);
	virtual void visit(area_node* n);
	virtual void visit(article_node* n);
	virtual void visit(aside_node* n);
	virtual void visit(audio_node* n);
	virtual void visit(b_node* n);
	virtual void visit(base_node* n);
	virtual void visit(bdi_node* n);
	virtual void visit(bdo_node* n);
	virtual void visit(blockquote_node* n);
	virtual void visit(br_node* n);
	virtual void visit(button_node* n);
	virtual void visit(canvas_node* n);
	virtual void visit(caption_node* n);
	virtual void visit(cite_node* n);
	virtual void visit(code_node* n);
	virtual void visit(col_node* n);
	virtual void visit(colgroup_node* n);
	virtual void visit(data_node* n);
	virtual void visit(datalist_node* n);
	virtual void visit(dd_node* n);
	virtual void visit(del_node* n);
	virtual void visit(details_node* n);
	virtual void visit(dfn_node* n);
	virtual void visit(dialog_node* n);
	virtual void visit(dl_node* n);
	virtual void visit(dt_node* n);
	virtual void visit(em_node* n);
	virtual void visit(embed_node* n);
	virtual void visit(fieldset_node* n);
	virtual void visit(figcaption_node* n);
	virtual void visit(figure_node* n);
	virtual void visit(footer_node* n);
	virtual void visit(form_node* n);
	virtual void visit(h1_node* n);
	virtual void visit(head_node* n);
	virtual void visit(header_node* n);
	virtual void visit(hgroup_node* n);
	virtual void visit(hr_node* n);
	virtual void visit(i_node* n);
	virtual void visit(iframe_node* n);
	virtual void visit(img_node* n);
	virtual void visit(input_node* n);
	virtual void visit(ins_node* n);
	virtual void visit(kbd_node* n);
	virtual void visit(label_node* n);
	virtual void visit(legend_node* n);
	virtual void visit(li_node* n);
	virtual void visit(link_node* n);
	virtual void visit(main_node* n);
	virtual void visit(map_node* n);
	virtual void visit(mark_node* n);
	virtual void visit(menu_node* n);
	virtual void visit(meta_node* n);
	virtual void visit(meter_node* n);
	virtual void visit(nav_node* n);
	virtual void visit(noscript_node* n);
	virtual void visit(object_node* n);
	virtual void visit(ol_node* n);
	virtual void visit(optgroup_node* n);
	virtual void visit(option_node* n);
	virtual void visit(output_node* n);
	virtual void visit(picture_node* n);
	virtual void visit(pre_node* n);
	virtual void visit(progress_node* n);
	virtual void visit(q_node* n);
	virtual void visit(rp_node* n);
	virtual void visit(rt_node* n);
	virtual void visit(ruby_node* n);
	virtual void visit(s_node* n);
	virtual void visit(samp_node* n);
	virtual void visit(script_node* n);
	virtual void visit(search_node* n);
	virtual void visit(section_node* n);
	virtual void visit(select_node* n);
	virtual void visit(slot_node* n);
	virtual void visit(small_node* n);
	virtual void visit(source_node* n);
	virtual void visit(span_node* n);
	virtual void visit(strong_node* n);
	virtual void visit(style_node* n);
	virtual void visit(sub_node* n);
	virtual void visit(summary_node* n);
	virtual void visit(sup_node* n);
	virtual void visit(tbody_node* n);
	virtual void visit(td_node* n);
	virtual void visit(template_node* n);
	virtual void visit(textarea_node* n);
	virtual void visit(tfoot_node* n);
	virtual void visit(th_node* n);
	virtual void visit(thead_node* n);
	virtual void visit(time_node* n);
	virtual void visit(title_node* n);
	virtual void visit(tr_node* n);
	virtual void visit(track_node* n);
	virtual void visit(u_node* n);
	virtual void visit(ul_node* n);
	virtual void visit(var_node* n);
	virtual void visit(video_node* n);
	virtual void visit(wbr_node* n);
};

#endif
