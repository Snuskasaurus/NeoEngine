//#include "../../Includes/Core/Physic.h"
//
//using namespace neo;
//
//Physic* Physic::Instance()
//{
//	static Collision instance;
//	return &instance;
//}
//
//void Physic::AddObject(Collider* _collider)
//{
//	PhysicObject::Tag tag = _object->GetTag();
//	Instance()->m_objects[tag].push_back(_object);
//}
//
//void Physic::RemoveObject(Collider* _object)
//{
//	PhysicObject::Tag tag = _object->GetTag();
//	for (size_t i = 0; i < Instance()->m_objects[tag].size(); i++)
//	{
//		if (Instance()->m_objects[tag][i] == _object)
//		{
//			Instance()->m_objects[tag].erase(Instance()->m_objects[tag].begin() + i);
//		}
//	}
//}
//
//void Physic::Update()
//{
//	for (size_t i1 = 0; i1 < (size_t)Collider::Tag::NB_TAGS - 1; i1++)
//	{
//		for (Collider* object1 : m_objects[i1])
//		{
//			for (size_t i2 = i1 + 1; i2 < (size_t)Collider::Tag::NB_TAGS; i2++)
//			{
//				for (Collider* object2 : m_objects[i2])
//				{
//					if (true == PhysicObject::CheckGenericCollision(*object1, *object2))
//					{
//						object1->OnCollision(*object2);
//						object2->OnCollision(*object1);
//					}
//				}
//			}
//		}
//	}
//}
//
