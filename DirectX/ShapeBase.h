#ifndef H_SHAPEBASE
#define H_SHAPEBASE
#include <vector>
#include "Shape.h"
#include "Bindable.h"

template<class T>
class ShapeBase : public Shape {
public:
	void ShapeBase<T>::Update() override {
        for (Bindable* bindable : bindables) {
            bindable->Bind(this);
        }
    }
protected:
    ShapeBase<T>(GameObject* gameObject)
        :
        Shape(gameObject)
    {}

	inline static std::vector<Bindable*> bindables;    
};
#endif