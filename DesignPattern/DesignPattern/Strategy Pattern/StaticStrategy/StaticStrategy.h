#pragma once

#include <vector>
#include <sstream>

namespace StaticStrategy
{
	enum class OutputFormat
	{
		markdown,
		html
	};

	struct ListStrategy
	{
		virtual void start(std::ostringstream& oss) {};
		virtual void end(std::ostringstream& oss) {};
		virtual void add_list_item(std::ostringstream& oss,
			const std::string& item) {};
	};

	template<typename LS>
	struct TextProcessor
	{
		void append_list(const std::vector<std::string> items);
		std::string str();
		void clear();

	private:
		std::ostringstream oss;
		LS list_strategy;
	};

	struct HtmlListStrategy : ListStrategy
	{
		virtual void start(std::ostringstream& oss) override;
		virtual void end(std::ostringstream& oss) override;
		virtual void add_list_item(std::ostringstream& oss,
			const std::string& item) override;
	};

	struct MarkdownStrategy : ListStrategy
	{
		virtual void add_list_item(std::ostringstream& oss,
			const std::string& item) override;
	};

	struct StaticStrategy
	{
		static void Run();
	};
}
