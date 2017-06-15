#include "Physics2D.h"
#include "Physics2DComponent.h"
#include <iostream>
#include <string>

Physics2D* Physics2D::instance = NULL;

Physics2D::Physics2D()
{
}


Physics2D::~Physics2D()
{
}

void Physics2D::AddEnabledEntity(Physics2DComponent * const & entity)
{
	enabledEntities.push_back(entity);
}

void Physics2D::RemoveEnabledEntity(Physics2DComponent * const & entity)
{
	for (int i = enabledEntities.size(); i--;)
	{
		if (enabledEntities.at(i) == entity) {
			enabledEntities.erase(enabledEntities.begin() + i);
		}
	}
	delete entity;
}

Physics2D * Physics2D::getInstance()
{
	return instance == NULL ? instance = new Physics2D() : instance;
}

void Physics2D::UpdatePhysics()
{
	while (1)
	{
		Collisions();
		UpdatePositions();
		SDL_Delay(RPGSAEMMOApp::GetFrameLock());
	}
}

void Physics2D::SeekCollisionableEntities()
{
	std::vector<Physics2DComponent*> collisionables;
	for (auto entity : enabledEntities)
	{
		if (entity->collisionType == CollisionTypes::SeparateAxis)
			collisionables.push_back(entity);
	}
	for (auto entity : collisionables)
	{
		for (auto currEntity : collisionables)
		{
			if (entity != currEntity)
			{
				if (entity->vertex.rect.pos.Distance(currEntity->vertex.rect.pos)
					< entity->vertex.rect.size.Lenght() * 2)
				{
					collisionableEntities.push_back(entity);
					break;
				}
			}
		}
	}
	collisionables.clear();
}


void Physics2D::CollisionDetection()
{
	std::vector<fVector2> axis1, axis2;
	fVector2 proj1, proj2;
	for (auto entity : collisionableEntities)
	{
		entity->isCollisioning = false;
		if (entity->collider != Colliders::Circle)
			axis1 = getCheckAxisArr(entity);
		for (auto collisioner : collisionableEntities)
		{
			float penetrationQ = 100000;
			fVector2 penetrationAxis;
			if (entity == collisioner) continue;
			if (collisioner->collider != Colliders::Circle)
				axis2 = getCheckAxisArr(collisioner);
			for (auto axis : axis1)
			{
				proj1 = entity->Project(axis);
				proj2 = collisioner->Project(axis);
				if (!proj1.Overlap(proj2))
					goto NoCollision;
				float penFac = proj1.GetOverlapFactor(proj2);
				if (penFac < penetrationQ)
				{
					penetrationQ = penFac;
					penetrationAxis = axis;
				}
			}
			for (auto axis : axis2)
			{
				proj1 = entity->Project(axis);
				proj2 = collisioner->Project(axis);
				if (!proj1.Overlap(proj2))
					goto NoCollision;
				float penFac = proj1.GetOverlapFactor(proj2);
				if (penFac < penetrationQ)
				{
					penetrationQ = penFac;
					penetrationAxis = axis;
				}
			}
			entity->isCollisioning = true;
			entity->collisionedEntities.push_back(collisioner);
			entity->penetrationQ = penetrationQ;
			entity->penetrationAxis = penetrationAxis;
		NoCollision:
			continue;
		}
	}
	//http://www.dyn4j.org/2010/01/sat/
	//http://www.metanetsoftware.com/technique/tutorialA.html
	//https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-basics-and-impulse-resolution--gamedev-6331
}

void Physics2D::Collisions()
{
	SetRotations();
	SeekCollisionableEntities();
	CollisionDetection();
	CollisionResolution();
	collisionableEntities.clear();
	UpdatePositions();
}

void Physics2D::CollisionResolution()
{
	for (auto i : collisionableEntities) 
	{
		if (i->isCollisioning)
		{
			for (auto collisions : i->collisionedEntities)
			{
				if (i->collisionResolution != CollisionResolutionTypes::NoCollision &&
					collisions->collisionResolution != CollisionResolutionTypes::NoCollision && collisions->isCollisioning) 
				{
					std::cout << collisions->penetrationAxis.Unit().x << " " << collisions->penetrationAxis.Unit().y << " " << collisions->penetrationQ << std::endl;
					collisions->Move(((collisions->penetrationAxis.Unit().x < 2 && collisions->penetrationAxis.Unit().x > -2 ? 
					 collisions->penetrationAxis.Unit() * ((collisions->getCenter().x - i->getCenter().x) < 0 || 
						 collisions->getCenter().y - i->getCenter().y < 0 ? 1 : -1) :
						fVector2::zero)  * (collisions->penetrationQ >= 0 && 
						collisions->penetrationQ < collisions->vertex.rect.size.Lenght() ? collisions->penetrationQ : 0)));
					if (collisions->collisionResolution == CollisionResolutionTypes::Block)
						collisions->SetVelocity(fVector2::zero);
					else
						collisions->SetVelocity(collisions->getVelocity() * -collisions->bounce);
					collisions->isCollisioning = false;
				}
			}
		}
	}
}

void Physics2D::UpdatePositions()
{
	for (auto i : enabledEntities)
		i->PhysicsUpdate();
}

std::vector<fVector2> Physics2D::getCheckAxisArr(Physics2DComponent * const & entity)
{
	std::vector<fVector2> testAxis;
	if (entity->collider == Colliders::Box)
	{
		testAxis.push_back((fVector2(entity->vertex.rect.size.x,0)).lNormal());
		testAxis.push_back((fVector2(0, entity->vertex.rect.size.y)).lNormal());
		testAxis.push_back((fVector2(entity->vertex.rect.size.x, 0)).rNormal());
		testAxis.push_back((fVector2(0, entity->vertex.rect.size.y)).rNormal());
	}
	else if (entity->collider == Colliders::Complex) {
		for (int i = 0; i < entity->vertex.complexVertex.vertex.size() - 1; ++i) 
		{
			testAxis.push_back(((entity->vertex.complexVertex.vertex.at(i + 1) + entity->vertex.complexVertex.pos) -
				(entity->vertex.complexVertex.vertex.at(i) + entity->vertex.complexVertex.pos)).rNormal());
		}
	}
	return testAxis;
}

void Physics2D::SetRotations()
{
	for (auto i : enabledEntities) {
		fVector2 center = i->getCenter();
		if (i->collider == Colliders::Box)
		{
			i->vertex.rect.pos.Rotate((i->angle), center);
			fVector2 size = i->vertex.rect.pos + i->vertex.rect.size;
			size.Rotate((i->angle), center);
			i->vertex.rect.size = size - i->vertex.rect.pos;
		}
	}
}

fVector2 Physics2D::findMinVertexRect(const PhysicsRect2D & vertex)
{
	fVector2 minVertex(vertex.pos.x,vertex.pos.y);
	if (minVertex.x > vertex.size.x + vertex.pos.x)
		minVertex.x = vertex.size.x + vertex.pos.x;
	if (minVertex.y > vertex.size.y + vertex.pos.y)
		minVertex.y = vertex.size.y + vertex.pos.y;
	return minVertex;
}

fVector2 Physics2D::findMaxVertexRect(const PhysicsRect2D & vertex)
{
	fVector2 minVertex(vertex.pos.x, vertex.pos.y);
	if (minVertex.x < vertex.size.x + vertex.pos.x)
		minVertex.x = vertex.size.x + vertex.pos.x;
	if (minVertex.y < vertex.size.y + vertex.pos.y)
		minVertex.y = vertex.size.y + vertex.pos.y;
	return minVertex;
}
