#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H

class text_node;
class abbr_node;
class a_node;
class body_node;
class bold_node;
class div_node;
class html_node;
class p_node;
class table_node;
class area_node;
class article_node;
class aside_node;
class audio_node;
class b_node;
class base_node;
class bdi_node;
class bdo_node;
class blockquote_node;
class br_node;
class button_node;
class canvas_node;
class caption_node;
class cite_node;
class code_node;
class col_node;
class colgroup_node;
class data_node;
class datalist_node;
class dd_node;
class del_node;
class details_node;
class dfn_node;
class dialog_node;
class dl_node;
class dt_node;
class em_node;
class embed_node;
class fieldset_node;
class figcaption_node;
class figure_node;
class footer_node;
class form_node;
class h1_node;
class head_node;
class header_node;
class hgroup_node;
class hr_node;
class i_node;
class iframe_node;
class img_node;
class input_node;
class ins_node;
class kbd_node;
class label_node;
class legend_node;
class li_node;
class link_node;
class main_node;
class map_node;
class mark_node;
class menu_node;
class meta_node;
class meter_node;
class nav_node;
class noscript_node;
class object_node;
class ol_node;
class optgroup_node;
class option_node;
class output_node;
class picture_node;
class pre_node;
class progress_node;
class q_node;
class rp_node;
class rt_node;
class ruby_node;
class s_node;
class samp_node;
class script_node;
class search_node;
class section_node;
class select_node;
class slot_node;
class small_node;
class source_node;
class span_node;
class strong_node;
class style_node;
class sub_node;
class summary_node;
class sup_node;
class tbody_node;
class td_node;
class template_node;
class textarea_node;
class tfoot_node;
class th_node;
class thead_node;
class time_node;
class title_node;
class tr_node;
class track_node;
class u_node;
class ul_node;
class var_node;
class video_node;
class wbr_node;

class node_visitor {
public:
	virtual void visit(text_node* n) = 0;
	virtual void visit(abbr_node* n) = 0;
	virtual void visit(a_node* n) = 0;
	virtual void visit(body_node* n) = 0;
	virtual void visit(bold_node* n) = 0;
	virtual void visit(div_node* n) = 0;
	virtual void visit(html_node* n) = 0;
	virtual void visit(p_node* n) = 0;
	virtual void visit(table_node* n) = 0;
	virtual void visit(area_node* n) = 0;
	virtual void visit(article_node* n) = 0;
	virtual void visit(aside_node* n) = 0;
	virtual void visit(audio_node* n) = 0;
	virtual void visit(b_node* n) = 0;
	virtual void visit(base_node* n) = 0;
	virtual void visit(bdi_node* n) = 0;
	virtual void visit(bdo_node* n) = 0;
	virtual void visit(blockquote_node* n) = 0;
	virtual void visit(br_node* n) = 0;
	virtual void visit(button_node* n) = 0;
	virtual void visit(canvas_node* n) = 0;
	virtual void visit(caption_node* n) = 0;
	virtual void visit(cite_node* n) = 0;
	virtual void visit(code_node* n) = 0;
	virtual void visit(col_node* n) = 0;
	virtual void visit(colgroup_node* n) = 0;
	virtual void visit(data_node* n) = 0;
	virtual void visit(datalist_node* n) = 0;
	virtual void visit(dd_node* n) = 0;
	virtual void visit(del_node* n) = 0;
	virtual void visit(details_node* n) = 0;
	virtual void visit(dfn_node* n) = 0;
	virtual void visit(dialog_node* n) = 0;
	virtual void visit(dl_node* n) = 0;
	virtual void visit(dt_node* n) = 0;
	virtual void visit(em_node* n) = 0;
	virtual void visit(embed_node* n) = 0;
	virtual void visit(fieldset_node* n) = 0;
	virtual void visit(figcaption_node* n) = 0;
	virtual void visit(figure_node* n) = 0;
	virtual void visit(footer_node* n) = 0;
	virtual void visit(form_node* n) = 0;
	virtual void visit(h1_node* n) = 0;
	virtual void visit(head_node* n) = 0;
	virtual void visit(header_node* n) = 0;
	virtual void visit(hgroup_node* n) = 0;
	virtual void visit(hr_node* n) = 0;
	virtual void visit(i_node* n) = 0;
	virtual void visit(iframe_node* n) = 0;
	virtual void visit(img_node* n) = 0;
	virtual void visit(input_node* n) = 0;
	virtual void visit(ins_node* n) = 0;
	virtual void visit(kbd_node* n) = 0;
	virtual void visit(label_node* n) = 0;
	virtual void visit(legend_node* n) = 0;
	virtual void visit(li_node* n) = 0;
	virtual void visit(link_node* n) = 0;
	virtual void visit(main_node* n) = 0;
	virtual void visit(map_node* n) = 0;
	virtual void visit(mark_node* n) = 0;
	virtual void visit(menu_node* n) = 0;
	virtual void visit(meta_node* n) = 0;
	virtual void visit(meter_node* n) = 0;
	virtual void visit(nav_node* n) = 0;
	virtual void visit(noscript_node* n) = 0;
	virtual void visit(object_node* n) = 0;
	virtual void visit(ol_node* n) = 0;
	virtual void visit(optgroup_node* n) = 0;
	virtual void visit(option_node* n) = 0;
	virtual void visit(output_node* n) = 0;
	virtual void visit(picture_node* n) = 0;
	virtual void visit(pre_node* n) = 0;
	virtual void visit(progress_node* n) = 0;
	virtual void visit(q_node* n) = 0;
	virtual void visit(rp_node* n) = 0;
	virtual void visit(rt_node* n) = 0;
	virtual void visit(ruby_node* n) = 0;
	virtual void visit(s_node* n) = 0;
	virtual void visit(samp_node* n) = 0;
	virtual void visit(script_node* n) = 0;
	virtual void visit(search_node* n) = 0;
	virtual void visit(section_node* n) = 0;
	virtual void visit(select_node* n) = 0;
	virtual void visit(slot_node* n) = 0;
	virtual void visit(small_node* n) = 0;
	virtual void visit(source_node* n) = 0;
	virtual void visit(span_node* n) = 0;
	virtual void visit(strong_node* n) = 0;
	virtual void visit(style_node* n) = 0;
	virtual void visit(sub_node* n) = 0;
	virtual void visit(summary_node* n) = 0;
	virtual void visit(sup_node* n) = 0;
	virtual void visit(tbody_node* n) = 0;
	virtual void visit(td_node* n) = 0;
	virtual void visit(template_node* n) = 0;
	virtual void visit(textarea_node* n) = 0;
	virtual void visit(tfoot_node* n) = 0;
	virtual void visit(th_node* n) = 0;
	virtual void visit(thead_node* n) = 0;
	virtual void visit(time_node* n) = 0;
	virtual void visit(title_node* n) = 0;
	virtual void visit(tr_node* n) = 0;
	virtual void visit(track_node* n) = 0;
	virtual void visit(u_node* n) = 0;
	virtual void visit(ul_node* n) = 0;
	virtual void visit(var_node* n) = 0;
	virtual void visit(video_node* n) = 0;
	virtual void visit(wbr_node* n) = 0;
	virtual ~node_visitor() {}
};

#endif
