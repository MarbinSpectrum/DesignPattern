#include "StaticStrategy.h"

#include <iostream>
#include <format>

namespace StaticStrategy
{
	template<typename LS>
	void TextProcessor<LS>::append_list(const std::vector<std::string> items)
	{
		list_strategy.start(oss);
		for (auto& item : items)
		{
			list_strategy.add_list_item(oss, item);
		}
		list_strategy.end(oss);
	}

	template<typename LS>
	std::string TextProcessor<LS>::str()
	{
		return oss.str();
	}

	template<typename LS>
	void TextProcessor<LS>::clear()
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

	void StaticStrategy::Run()
	{
		TextProcessor<MarkdownStrategy> tpm;
		tpm.append_list({ "foo","bar","baz" });
		std::cout << tpm.str() << "\n";

		TextProcessor<HtmlListStrategy> tph;
		tph.append_list({ "foo","bar","baz" });
		std::cout << tph.str() << "\n";
	}
};
