#pragma once

#include <string>
#include <QDate>

#include <variant>

namespace month_flow::data
{
	using VariantDeadline = std::variant<int, QDate>; // [periodic day of month, single deadline]

	struct Task
	{
		std::string name;
		std::string description;
		VariantDeadline deadline;
	};
}
