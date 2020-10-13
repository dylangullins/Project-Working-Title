#include "PhysicsPlayground.h"

PhysicsPlayground::PhysicsPlayground(std::string name)
	: Scene(name)
{
	//No Gravity, top down scene 
	m_gravity = b2Vec2(0.f, 0.f);
	m_physicsWorld->SetGravity(m_gravity);
}


void PhysicsPlayground::InitScene(float windowWidth, float windowHeight)
{
	//Dynamically allocates the register 
	m_sceneReg = new entt::registry;

	//Attach the resister
	ECS::AttachRegister(m_sceneReg);

	//Sets up aspect ratio of the camera 

	float aspectRatio = windowWidth / windowHeight;

	//creates a Main camera
	{
		auto entity = ECS::CreateEntity();
		ECS::SetIsMainCamera(entity, true);

		//Creates new orthrographic camera
		ECS::AttachComponent<Camera>(entity);
		ECS::AttachComponent<HorizontalScroll>(entity);
		ECS::AttachComponent<VerticalScroll>(entity);

		vec4 temp = vec4(-75.F, 75.F, -75.F, 75.F);
		ECS::GetComponent<Camera>(entity).SetOrthoSize(temp);
		ECS::GetComponent<Camera>)entity).SetWindowSize(vec2(float(windowWidth), (float windowHeight)));
		ECS::GetComponent<Camera>(entity).Orthographic(aspectRatio,  temp.x, temp.y, temp.z, temp.w, -100.f, 100.f);
		

	}

}

void PhysicsPlayground::Update()
{
	Scene::AdjustScrollOffset();
}


void PhysicsPlayground::KeyboardHold()
{
}

void PhysicsPlayground::KeyboardDown()
{
}

void PhysicsPlayground::KeyboardUp()
{
}
