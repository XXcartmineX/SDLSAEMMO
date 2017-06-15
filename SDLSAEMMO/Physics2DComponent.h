#pragma once
#include <chrono>
#include <deque>
#include "Physics2D.h"
#include "PhysicsRect2D.h"

typedef struct CircleCollider2D {
	float radius;
	fVector2 pos;
	~CircleCollider2D() {}
	CircleCollider2D() {}
}CircleCollider2D;

typedef struct ComplexCollider2D {
	std::vector<fVector2> vertex;
	fVector2 pos;
}ComplexCollider2D;

typedef union Verts{
	PhysicsRect2D rect;
	ComplexCollider2D complexVertex;
	CircleCollider2D circleCollider;
	~Verts() {}
	Verts(PhysicsRect2D _rect) { rect = _rect; }
	Verts(std::vector<fVector2> _vertex, fVector2 _pos) { 
		complexVertex.vertex = _vertex;
		complexVertex.pos = _pos;
	}
	Verts(CircleCollider2D _collider) {
		circleCollider = _collider;
	}
	Verts() {}
}Verts;

class Physics2DComponent
{
public:
	Physics2DComponent(std::string _name, fVector2* _position);
	~Physics2DComponent();
	inline fVector2 getVelocity() { return velocity; }
	inline float getSpeed() { return speed = velocity.Lenght(); }
	inline fVector2 getAcceleration() { return acceleration; }
	void SetVelocity(const fVector2& _newVel);
	void SetVelocity(float _x, float _y);
	void AddVelocity(const fVector2& _newVel);
	void AddVelocity(float _x, float _y);
	void Move(const fVector2& _movePos);
	void Move(float _x, float _y);
	void UpdatePosition(fVector2 newPos);
	fVector2 Project(fVector2& axis);
	void PhysicsUpdate();
	fVector2 getCenter();
	fVector2* position = NULL;
	std::string name = "";
	std::string tag = "";
	bool isCollisioning = false;
	short collisionDirection : 3;
	short collisionType : 2;
	short collider : 2;
	short collisionResolution : 2;
	float friction = .03f;
	float penetrationQ;
	fVector2 penetrationAxis;
	float angle = 0;
	float rotAngle = 0;
	float mass = 1;
	float bounce = 0;
	Verts vertex;
	std::vector<Physics2DComponent*> collisionedEntities;
	std::chrono::milliseconds physicsTimerStart;
	std::chrono::milliseconds physicsTimer;
private:
	bool velocityIsManual = false;
	bool centerMoved = true;
	float velocityThreshold = .15f;
	fVector2 center;
	fVector2 velocity = fVector2::zero;
	fVector2 acceleration = fVector2::zero;
	float speed = 0;
	std::deque<fVector2> last3Positions;
};

