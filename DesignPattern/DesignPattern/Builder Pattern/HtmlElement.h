#pragma once

#include <string>
#include <vector>
#include <format>
#include <iostream>
#include "FluentBuilder.h"
#include "SimpleBuilder.h"
#include "BuilderScenario.h"

class SimpleBuilder;
class FluentBuilder;
class BuilderScenario;

class HtmlElement
{
	friend class SimpleBuilder;
	friend class FluentBuilder;
	friend class BuilderScenario;

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