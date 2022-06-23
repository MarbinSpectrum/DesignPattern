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

	//생성자를 숨기는 대신 객체 자체에 팩토리 메서드를 두어서 빌더를 생성할  수 있게 한다.
	static std::unique_ptr<FluentBuilder> build(const std::string& root_name);

	std::string str() const;

	//빌더를 사용하지 않으면 객체 생성을 불가능하도록 설정
protected:
	HtmlElement();
	HtmlElement(const std::string& name, const std::string& text);
};