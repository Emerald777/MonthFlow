#pragma once

#include <string>
#include <QDate>

#include <variant>

namespace month_flow
{
	using VariantDeadline = std::variant<int, QDate>; // [periodic day of month, single deadline]

	struct TaskData
	{
		std::string name;
		std::string description;
		VariantDeadline deadline;
	};
}
