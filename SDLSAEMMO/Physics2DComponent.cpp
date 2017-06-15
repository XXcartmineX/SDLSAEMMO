#include "Physics2DComponent.h"
#include "RPGSAEMMOApp.h"
#include <iostream>


Physics2DComponent::Physics2DComponent(std::string _name, fVector2* _position)
{
	name = _name;
	position = _position;
	Physics2D::getInstance()->AddEnabledEntity(this);
}

Physics2DComponent::~Physics2DComponent()
{
	Physics2D::getInstance()->RemoveEnabledEntity(this);
}

void Physics2DComponent::SetVelocity(const fVector2 & _newVel)
{
	velocityIsManual = true;
	velocity = _newVel;
}

void Physics2DComponent::SetVelocity(float _x, float _y)
{
	velocityIsManual = true;
	velocity.x = _x;
	velocity.y = _y;
}

void Physics2DComponent::AddVelocity(const fVector2 & _newVel)
{
	velocityIsManual = true;
	velocity += _newVel;
}

void Physics2DComponent::AddVelocity(float _x, float _y)
{
	velocityIsManual = true;
	velocity += fVector2(_x, _y);
}

void Physics2DComponent::Move(const fVector2 & _movePos)
{
	UpdatePosition(_movePos);
	velocityIsManual = true;
}

void Physics2DComponent::Move(float _x, float _y)
{
	UpdatePosition(fVector2(_x,_y));
	velocityIsManual = true;
}

void Physics2DComponent::PhysicsUpdate()
{
	if (velocity != fVector2::zero)
		velocity -= fVector2(velocity * friction);
	last3Positions.push_back(*position);
	if (last3Positions.size() > 3)
	{
		last3Positions.pop_front();
		physicsTimer = std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::system_clock::now().time_since_epoch()) - physicsTimerStart;
		if(!velocityIsManual)
			velocity = (last3Positions.at(2) - last3Positions.at(1))/ ((float)RPGSAEMMOApp::getDeltaTime() / 10);
		acceleration = ((last3Positions.at(2) - last3Positions.at(1)) -
			(last3Positions.at(1) - last3Positions.at(0))) / (float)physicsTimer.count();
	}
	if ((velocity.x < velocityThreshold && velocity.x > 0) ||
		(velocity.x > -velocityThreshold && velocity.x < 0))
		velocity.x = 0;
	if ((velocity.y < velocityThreshold && velocity.y > 0) ||
		(velocity.y > -velocityThreshold && velocity.y < 0))
		velocity.y = 0;
	UpdatePosition(velocity);
}

fVector2 Physics2DComponent::getCenter()
{
	if (centerMoved)
	{
		std::vector<fVector2> vertexy;
		if (collider == Colliders::Box ||
			collider == Colliders::Complex)
		{
			if (collider == Colliders::Box)
			{
				vertexy.push_back(vertex.rect.pos);
				vertexy.push_back(vertex.rect.size + vertex.rect.pos);
			}
			else vertexy = vertex.complexVertex.vertex;
			center = fVector2::zero;
			for (auto i : vertexy)
			{
				center += i;
			}
			center /= (float)vertexy.size();
			centerMoved = false;
			return center;
		}
	}
	else return center;
	return center;
}

void Physics2DComponent::UpdatePosition(fVector2 newPos)
{
	if (newPos != fVector2::zero)
	{
		centerMoved = true;
		if (physicsTimerStart.count() == 0 || velocity == fVector2::zero)
			physicsTimerStart = 
			std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::system_clock::now().time_since_epoch());
	}
	*position += newPos;
	if (collider == Colliders::Box)
		vertex.rect.pos = *position;
	else if (collider == Colliders::Complex)
		vertex.complexVertex.pos = *position;
	else if (collider == Colliders::Circle)
		vertex.circleCollider.pos = *position;
}

fVector2 Physics2DComponent::Project(fVector2 & axis)
{
	float min, max;
	axis = axis.Unit();
	float tmp;
	fVector2 rotPos = vertex.rect.pos;
	rotPos = rotPos.Rotate(this->rotAngle,this->getCenter());
	if (collider == Colliders::Box)
	{
		min = max = axis.Dot(rotPos);
		tmp = axis.Dot(fVector2(rotPos.x + vertex.rect.size.x, rotPos.y));
		if (min > tmp) min = tmp;
		else if (max < tmp) max = tmp;
		tmp = axis.Dot(fVector2(rotPos.x + vertex.rect.size.x, rotPos.y + vertex.rect.size.y));
		if (min > tmp) min = tmp;
		else if (max < tmp) max = tmp;
		tmp = axis.Dot(fVector2(rotPos.x, rotPos.y + vertex.rect.size.y));
		if (min > tmp) min = tmp;
		else if (max < tmp) max = tmp;
	}
	else if (collider == Colliders::Complex)
	{
		min = max = axis.Dot(vertex.complexVertex.vertex.at(0));
		for (auto vert : vertex.complexVertex.vertex) 
		{
			tmp = axis.Dot(vert);
			if (min > tmp) min = tmp;
			else if (max < tmp) max = tmp;
		}
	}
	return fVector2(min, max);
}
