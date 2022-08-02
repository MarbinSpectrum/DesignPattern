#include "DynamicStrategy.h"

#include <iostream>
#include <format>

namespace DynamicStrategy
{
	void TextProcessor::append_list(const std::vector<std::string> items)
	{
		list_strategy->start(oss);
		for (auto& item : items)
		{
			list_strategy->add_list_item(oss, item);
		}
		list_strategy->end(oss);
	}

	void TextProcessor::set_out_format(const OutputFormat format)
	{
		switch (format)
		{
			case OutputFormat::markdown:
			{
				list_strategy = std::make_unique<MarkdownStrategy>();
			}
			break;
			case OutputFormat::html:
			{
				list_strategy = std::make_unique<HtmlListStrategy>();
			}
			break;
		}
	}

	std::string TextProcessor::str()
	{
		return oss.str();
	}

	void TextProcessor::clear()
	{
		oss.clear();
	}

	void HtmlListStrategy::start(std::ostringstream& oss)
	{
		oss << "<ul>\n";
	}

	void HtmlListStrategy::end(std::ostringstream& oss)
	{
		oss << "</ul>\n";
	}

	void HtmlListStrategy::add_list_item(std::ostringstream& oss,
		const std::string& item)
	{
		oss << "<li>" << item << "</li>\n";
	}

	void MarkdownStrategy::add_list_item(std::ostringstream& oss,
		const std::string& item)
	{
		oss << " * " << item << "\n";
	}

	void DynamicStrategy::Run()
	{
		TextProcessor tp;
		tp.set_out_format(OutputFormat::markdown);
		tp.append_list({ "foo","bar","baz" });
		std::cout << tp.str() << "\n";

		tp.clear();
		tp.set_out_format(OutputFormat::html);
		tp.append_list({ "foo","bar","baz" });
		std::cout << tp.str() << "\n";
	}
};
