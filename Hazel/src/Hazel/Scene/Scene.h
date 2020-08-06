#pragma once

#include "Hazel/Core/Timestep.h"
#include "Hazel/Renderer/Renderer2D.h"

#include <entt.hpp>

namespace Hazel {

	class Entity;

	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());

		// TEMP
		entt::registry& Reg() { return m_Registry; }

		void OnUpdate(Timestep ts);
	private:
		entt::registry m_Registry;

	
		friend class Entity;
	};

}