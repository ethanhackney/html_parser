#include "dump_visitor.h"

using std::cout;

void dump_visitor::indent(int space)
{
        for (auto i = 0; i < space; i++)
                cout << " ";
}

void dump_visitor::visit(text_node* n)
{
        indent(_indent);
        cout << "text_node{\n";
        indent(_indent + 2);
        cout << '"' << (char)n->c() << "\"\n";
        indent(_indent);
        cout << "}";
}

void dump_visitor::dump_attrs(std::unordered_map<std::string,std::string>& attrs)
{
        indent(_indent);
        cout << "attrs: {\n";
        for (auto p : attrs) {
                indent(_indent + 2);
                cout << p.first << ": " << p.second << ",\n";
        }
        indent(_indent);
        cout << "}";
}

void dump_visitor::dump_kids(std::vector<node*>& kids)
{
        indent(_indent);
        cout << "kids: [\n";
        for (auto k : kids) {
                _indent += 2;
                k->visit(this);
                cout << ",\n";
                _indent -= 2;

        }
        indent(_indent);
        cout << "]";
}

void dump_visitor::dump_internal_node(const std::string& name, internal_node* n)
{
        indent(_indent);
        cout << name << "{\n";

        _indent += 2;
        dump_attrs(n->attrs());
        _indent -= 2;
        cout << ",\n";

        _indent += 2;
        dump_kids(n->kids());
        _indent -= 2;
        cout << "\n";

        indent(_indent);
        cout << "}";
}

void dump_visitor::visit(abbr_node* n)
{
	dump_internal_node("abbr_node", n);
}

void dump_visitor::visit(a_node* n)
{
	dump_internal_node("a_node", n);
}

void dump_visitor::visit(body_node* n)
{
	dump_internal_node("body_node", n);
}

void dump_visitor::visit(bold_node* n)
{
	dump_internal_node("bold_node", n);
}

void dump_visitor::visit(div_node* n)
{
	dump_internal_node("div_node", n);
}

void dump_visitor::visit(html_node* n)
{
	dump_internal_node("html_node", n);
}

void dump_visitor::visit(p_node* n)
{
	dump_internal_node("p_node", n);
}

void dump_visitor::visit(table_node* n)
{
	dump_internal_node("table_node", n);
}

void dump_visitor::visit(area_node* n)
{
	dump_internal_node("area_node", n);
}

void dump_visitor::visit(article_node* n)
{
	dump_internal_node("article_node", n);
}

void dump_visitor::visit(aside_node* n)
{
	dump_internal_node("aside_node", n);
}

void dump_visitor::visit(audio_node* n)
{
	dump_internal_node("audio_node", n);
}

void dump_visitor::visit(b_node* n)
{
	dump_internal_node("b_node", n);
}

void dump_visitor::visit(base_node* n)
{
	dump_internal_node("base_node", n);
}

void dump_visitor::visit(bdi_node* n)
{
	dump_internal_node("bdi_node", n);
}

void dump_visitor::visit(bdo_node* n)
{
	dump_internal_node("bdo_node", n);
}

void dump_visitor::visit(blockquote_node* n)
{
	dump_internal_node("blockquote_node", n);
}

void dump_visitor::visit(br_node* n)
{
	dump_internal_node("br_node", n);
}

void dump_visitor::visit(button_node* n)
{
	dump_internal_node("button_node", n);
}

void dump_visitor::visit(canvas_node* n)
{
	dump_internal_node("canvas_node", n);
}

void dump_visitor::visit(caption_node* n)
{
	dump_internal_node("caption_node", n);
}

void dump_visitor::visit(cite_node* n)
{
	dump_internal_node("cite_node", n);
}

void dump_visitor::visit(code_node* n)
{
	dump_internal_node("code_node", n);
}

void dump_visitor::visit(col_node* n)
{
	dump_internal_node("col_node", n);
}

void dump_visitor::visit(colgroup_node* n)
{
	dump_internal_node("colgroup_node", n);
}

void dump_visitor::visit(data_node* n)
{
	dump_internal_node("data_node", n);
}

void dump_visitor::visit(datalist_node* n)
{
	dump_internal_node("datalist_node", n);
}

void dump_visitor::visit(dd_node* n)
{
	dump_internal_node("dd_node", n);
}

void dump_visitor::visit(del_node* n)
{
	dump_internal_node("del_node", n);
}

void dump_visitor::visit(details_node* n)
{
	dump_internal_node("details_node", n);
}

void dump_visitor::visit(dfn_node* n)
{
	dump_internal_node("dfn_node", n);
}

void dump_visitor::visit(dialog_node* n)
{
	dump_internal_node("dialog_node", n);
}

void dump_visitor::visit(dl_node* n)
{
	dump_internal_node("dl_node", n);
}

void dump_visitor::visit(dt_node* n)
{
	dump_internal_node("dt_node", n);
}

void dump_visitor::visit(em_node* n)
{
	dump_internal_node("em_node", n);
}

void dump_visitor::visit(embed_node* n)
{
	dump_internal_node("embed_node", n);
}

void dump_visitor::visit(fieldset_node* n)
{
	dump_internal_node("fieldset_node", n);
}

void dump_visitor::visit(figcaption_node* n)
{
	dump_internal_node("figcaption_node", n);
}

void dump_visitor::visit(figure_node* n)
{
	dump_internal_node("figure_node", n);
}

void dump_visitor::visit(footer_node* n)
{
	dump_internal_node("footer_node", n);
}

void dump_visitor::visit(form_node* n)
{
	dump_internal_node("form_node", n);
}

void dump_visitor::visit(h1_node* n)
{
	dump_internal_node("h1_node", n);
}

void dump_visitor::visit(head_node* n)
{
	dump_internal_node("head_node", n);
}

void dump_visitor::visit(header_node* n)
{
	dump_internal_node("header_node", n);
}

void dump_visitor::visit(hgroup_node* n)
{
	dump_internal_node("hgroup_node", n);
}

void dump_visitor::visit(hr_node* n)
{
	dump_internal_node("hr_node", n);
}

void dump_visitor::visit(i_node* n)
{
	dump_internal_node("i_node", n);
}

void dump_visitor::visit(iframe_node* n)
{
	dump_internal_node("iframe_node", n);
}

void dump_visitor::visit(img_node* n)
{
	dump_internal_node("img_node", n);
}

void dump_visitor::visit(input_node* n)
{
	dump_internal_node("input_node", n);
}

void dump_visitor::visit(ins_node* n)
{
	dump_internal_node("ins_node", n);
}

void dump_visitor::visit(kbd_node* n)
{
	dump_internal_node("kbd_node", n);
}

void dump_visitor::visit(label_node* n)
{
	dump_internal_node("label_node", n);
}

void dump_visitor::visit(legend_node* n)
{
	dump_internal_node("legend_node", n);
}

void dump_visitor::visit(li_node* n)
{
	dump_internal_node("li_node", n);
}

void dump_visitor::visit(link_node* n)
{
	dump_internal_node("link_node", n);
}

void dump_visitor::visit(main_node* n)
{
	dump_internal_node("main_node", n);
}

void dump_visitor::visit(map_node* n)
{
	dump_internal_node("map_node", n);
}

void dump_visitor::visit(mark_node* n)
{
	dump_internal_node("mark_node", n);
}

void dump_visitor::visit(menu_node* n)
{
	dump_internal_node("menu_node", n);
}

void dump_visitor::visit(meta_node* n)
{
	dump_internal_node("meta_node", n);
}

void dump_visitor::visit(meter_node* n)
{
	dump_internal_node("meter_node", n);
}

void dump_visitor::visit(nav_node* n)
{
	dump_internal_node("nav_node", n);
}

void dump_visitor::visit(noscript_node* n)
{
	dump_internal_node("noscript_node", n);
}

void dump_visitor::visit(object_node* n)
{
	dump_internal_node("object_node", n);
}

void dump_visitor::visit(ol_node* n)
{
	dump_internal_node("ol_node", n);
}

void dump_visitor::visit(optgroup_node* n)
{
	dump_internal_node("optgroup_node", n);
}

void dump_visitor::visit(option_node* n)
{
	dump_internal_node("option_node", n);
}

void dump_visitor::visit(output_node* n)
{
	dump_internal_node("output_node", n);
}

void dump_visitor::visit(picture_node* n)
{
	dump_internal_node("picture_node", n);
}

void dump_visitor::visit(pre_node* n)
{
	dump_internal_node("pre_node", n);
}

void dump_visitor::visit(progress_node* n)
{
	dump_internal_node("progress_node", n);
}

void dump_visitor::visit(q_node* n)
{
	dump_internal_node("q_node", n);
}

void dump_visitor::visit(rp_node* n)
{
	dump_internal_node("rp_node", n);
}

void dump_visitor::visit(rt_node* n)
{
	dump_internal_node("rt_node", n);
}

void dump_visitor::visit(ruby_node* n)
{
	dump_internal_node("ruby_node", n);
}

void dump_visitor::visit(s_node* n)
{
	dump_internal_node("s_node", n);
}

void dump_visitor::visit(samp_node* n)
{
	dump_internal_node("samp_node", n);
}

void dump_visitor::visit(script_node* n)
{
	dump_internal_node("script_node", n);
}

void dump_visitor::visit(search_node* n)
{
	dump_internal_node("search_node", n);
}

void dump_visitor::visit(section_node* n)
{
	dump_internal_node("section_node", n);
}

void dump_visitor::visit(select_node* n)
{
	dump_internal_node("select_node", n);
}

void dump_visitor::visit(slot_node* n)
{
	dump_internal_node("slot_node", n);
}

void dump_visitor::visit(small_node* n)
{
	dump_internal_node("small_node", n);
}

void dump_visitor::visit(source_node* n)
{
	dump_internal_node("source_node", n);
}

void dump_visitor::visit(span_node* n)
{
	dump_internal_node("span_node", n);
}

void dump_visitor::visit(strong_node* n)
{
	dump_internal_node("strong_node", n);
}

void dump_visitor::visit(style_node* n)
{
	dump_internal_node("style_node", n);
}

void dump_visitor::visit(sub_node* n)
{
	dump_internal_node("sub_node", n);
}

void dump_visitor::visit(summary_node* n)
{
	dump_internal_node("summary_node", n);
}

void dump_visitor::visit(sup_node* n)
{
	dump_internal_node("sup_node", n);
}

void dump_visitor::visit(tbody_node* n)
{
	dump_internal_node("tbody_node", n);
}

void dump_visitor::visit(td_node* n)
{
	dump_internal_node("td_node", n);
}

void dump_visitor::visit(template_node* n)
{
	dump_internal_node("template_node", n);
}

void dump_visitor::visit(textarea_node* n)
{
	dump_internal_node("textarea_node", n);
}

void dump_visitor::visit(tfoot_node* n)
{
	dump_internal_node("tfoot_node", n);
}

void dump_visitor::visit(th_node* n)
{
	dump_internal_node("th_node", n);
}

void dump_visitor::visit(thead_node* n)
{
	dump_internal_node("thead_node", n);
}

void dump_visitor::visit(time_node* n)
{
	dump_internal_node("time_node", n);
}

void dump_visitor::visit(title_node* n)
{
	dump_internal_node("title_node", n);
}

void dump_visitor::visit(tr_node* n)
{
	dump_internal_node("tr_node", n);
}

void dump_visitor::visit(track_node* n)
{
	dump_internal_node("track_node", n);
}

void dump_visitor::visit(u_node* n)
{
	dump_internal_node("u_node", n);
}

void dump_visitor::visit(ul_node* n)
{
	dump_internal_node("ul_node", n);
}

void dump_visitor::visit(var_node* n)
{
	dump_internal_node("var_node", n);
}

void dump_visitor::visit(video_node* n)
{
	dump_internal_node("video_node", n);
}

void dump_visitor::visit(wbr_node* n)
{
	dump_internal_node("wbr_node", n);
}

