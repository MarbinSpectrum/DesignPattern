#pragma once

#include <string>
#include <vector>
#include <format>
#include <iostream>
#include "Fluent Builder/FluentBuilder.h"
#include "Simple Builder/SimpleBuilder.h"

class SimpleBuilder;
class FluentBuilder;

class HtmlElement
{
	friend class SimpleBuilder;
	friend class FluentBuilder;

public:
	std::string name;
	std::string text;
	std::vector<HtmlElement> elements;

	//�����ڸ� ����� ��� ��ü ��ü�� ���丮 �޼��带 �ξ ������ ������  �� �ְ� �Ѵ�.
	static std::unique_ptr<FluentBuilder> build(const std::string& root_name);

	std::string str() const;

	//������ ������� ������ ��ü ������ �Ұ����ϵ��� ����
protected:
	HtmlElement();
	HtmlElement(const std::string& name, const std::string& text);
};