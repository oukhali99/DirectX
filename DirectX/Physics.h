#ifndef H_PHYSICS
#define H_PHYSICS
#include "btBulletDynamicsCommon.h"

class Physics {
public:
	static void Init();
	static Physics* GetInstance();

	void AddRigidbody(btRigidBody* rigidbody);
	void Update();
private:
	Physics();
	~Physics();
	inline static Physics* instance;

	btDiscreteDynamicsWorld* dynamicsWorld;
};
#endif
