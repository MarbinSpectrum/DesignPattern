#pragma once

#include <vector>
#include <sstream>

namespace DynamicStrategy
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

	struct TextProcessor
	{
		void append_list(const std::vector<std::string> items);
		void set_out_format(const OutputFormat format);
		std::string str();
		void clear();

	private:
		std::ostringstream oss;
		std::unique_ptr<ListStrategy> list_strategy;
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

	struct DynamicStrategy
	{
		static void Run();
	};
}
