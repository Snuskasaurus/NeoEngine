#pragma once

namespace neo
{
	class NEOENGINE_API State
	{
	public:
		void Update();
		void Draw() const;
		virtual void OnUpdate();
		virtual void OnDraw() const;
	};
}