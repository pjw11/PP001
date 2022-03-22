#pragma once
namespace Musoum
{
	class MCommand
	{
	public:
		MCommand() {}
		virtual ~MCommand() {}

		virtual void Execute() {}
	};
}
