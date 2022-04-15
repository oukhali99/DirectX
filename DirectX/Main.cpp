#include "Main.h"
#include "Cube.h"
#include "Clock.h"
#include "Mouse.h"
#include "Pyramid.h"
#include "btBulletDynamicsCommon.h"
#include "Window.h"
#include "Physics.h"
#include "GameObject.h"
#include "Game.h"
#include "Rigidbody.h"
#include "Shape.h"
#include "Script.h"
#include "Keyboard.h"
#include "Texture.h"
#include "Gui.h"
#include "Camera.h"

float foo = 0;

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
) {
    try {
        HWND hWnd;
        ZeroMemory(&hWnd, sizeof(hWnd));
        Window window(hInstance, hPrevInstance, lpCmdLine, nCmdShow, hWnd);

        Game::Init(hWnd);
        Physics::Init();
        Graphics::Init(hWnd, 0.5f, 50.0f);
        Gui::Init(hWnd);

        FaceColor faceColors[] = {
                { 1.0f, 0.0f, 0.0f, 1.0f },
                { 0.0f, 1.0f, 0.0f, 1.0f },
                { 0.0f, 0.0f, 1.0f, 1.0f },
                { 0.0f, 0.0f, 1.0f, 1.0f },
                { 1.0f, 0.0f, 1.0f, 1.0f },
                { 1.0f, 1.0f, 0.0f, 1.0f },
        };

        // Camera
        {
            btVector3 size(1, 1, 1);

            btTransform transform;
            transform.setIdentity();
            transform.setOrigin(btVector3(0, 0, 0));

            GameObject* object = new GameObject(transform, size);

            object->AddComponent<Camera>();
            Camera* camera = object->GetComponent<Camera>();
            Game::GetInstance()->SetMainCamera(camera);

            object->AddComponent<Script>();
            Script* script = object->GetComponent<Script>();
            script->SetOnUpdate([](GameObject* gameObject) {
                for (WPARAM wParam : *Keyboard::GetInstance()->GetPressedKeys()) {
                    float deltaTime = Clock::GetSingleton().GetTimeSinceStart() - Game::GetInstance()->GetLastUpdateTime();
                    btQuaternion unitTorque(0, 0, 0);
                    btScalar torqueMagnitude = 2.0f * deltaTime;
                    if (wParam == 'W') {
                        unitTorque.setX(torqueMagnitude);
                    }
                    else if (wParam == 'S') {
                        unitTorque.setX(-torqueMagnitude);
                    }
                    else if (wParam == 'D') {
                        unitTorque.setY(-torqueMagnitude);
                    }
                    else if (wParam == 'A') {
                        unitTorque.setY(torqueMagnitude);
                    }

                    btTransform oldTransform = gameObject->GetTransform();
                    btTransform newTransform = oldTransform;

                    btQuaternion newRotation = oldTransform.getRotation() * unitTorque;
                    foo = newRotation.y();

                    newTransform.setRotation(newRotation);
                    gameObject->SetTransform(newTransform);
                }
            });
        }

        // Ground
        {
            btVector3 size(1, 1, 1);

            btTransform transform;
            transform.setIdentity();
            transform.setOrigin(btVector3(0, -2.1f, 5));

            GameObject* object = new GameObject(transform, size);

            object->AddComponent<Cube>();
            Shape* shape = object->GetComponent<Shape>();

            Texture* texture = new Texture("brick.jpg");
            shape->SetTexture(texture);

            object->AddComponent<Rigidbody>();
            Rigidbody* rb = object->GetComponent<Rigidbody>();
            rb->SetMass(0);
            rb->SetIsKinematic(true);

            object->AddComponent<Script>();
            Script* script = object->GetComponent<Script>();
            script->SetOnUpdate([rb](GameObject* gameObject) {
                for (WPARAM wParam : *Keyboard::GetInstance()->GetPressedKeys()) {
                    float deltaTime = Clock::GetSingleton().GetTimeSinceStart() - Game::GetInstance()->GetLastUpdateTime();
                    btVector3 unitTorque(0, 0, 0);
                    btScalar torqueMagnitude = 2.0f * deltaTime;

                    if (wParam == 'W') {
                        unitTorque.setY(1);
                    }
                    else if (wParam == 'S') {
                        unitTorque.setY(-1);
                    }
                    else if (wParam == 'D') {
                        unitTorque.setX(1);
                    }
                    else if (wParam == 'A') {
                        unitTorque.setX(-1);
                    }

                    //rb->ApplyImpulse(unitTorque * torqueMagnitude);
                }
                });
        }

        // Cube
        {
            btVector3 size(1, 1, 1);

            btTransform transform;
            transform.setIdentity();
            transform.setOrigin(btVector3(0, 0, 5));

            GameObject* object = new GameObject(transform, size);

            object->AddComponent<Cube>();
            Shape* shape = object->GetComponent<Shape>();

            Texture* texture = new Texture("brick.jpg");
            shape->SetTexture(texture);

            object->AddComponent<Rigidbody>();
            Rigidbody* rb = object->GetComponent<Rigidbody>();
            rb->SetMass(0);
            rb->SetIsKinematic(true);

            object->AddComponent<Script>();
            Script* script = object->GetComponent<Script>();
            script->SetOnUpdate([rb](GameObject* gameObject) {
                for (WPARAM wParam : *Keyboard::GetInstance()->GetPressedKeys()) {
                    float deltaTime = Clock::GetSingleton().GetTimeSinceStart() - Game::GetInstance()->GetLastUpdateTime();
                    btVector3 unitTorque(0, 0, 0);
                    btScalar torqueMagnitude = 2.0f * deltaTime;

                    if (wParam == 'W') {
                        unitTorque.setY(1);
                    }
                    else if (wParam == 'S') {
                        unitTorque.setY(-1);
                    }
                    else if (wParam == 'D') {
                        unitTorque.setX(1);
                    }
                    else if (wParam == 'A') {
                        unitTorque.setX(-1);
                    }

                    //rb->ApplyImpulse(unitTorque * torqueMagnitude);
                }
                });
        }

        // Cube
        {
            btVector3 size(1, 1, 1);

            btTransform transform;
            transform.setIdentity();
            transform.setOrigin(btVector3(0, 0, -5));

            GameObject* object = new GameObject(transform, size);

            object->AddComponent<Cube>();
            Shape* shape = object->GetComponent<Shape>();

            Texture* texture = new Texture("brick.jpg");
            shape->SetTexture(texture);

            object->AddComponent<Rigidbody>();
            Rigidbody* rb = object->GetComponent<Rigidbody>();
            rb->SetMass(0);
            rb->SetIsKinematic(true);

            object->AddComponent<Script>();
            Script* script = object->GetComponent<Script>();
            script->SetOnUpdate([rb](GameObject* gameObject) {
                for (WPARAM wParam : *Keyboard::GetInstance()->GetPressedKeys()) {
                    float deltaTime = Clock::GetSingleton().GetTimeSinceStart() - Game::GetInstance()->GetLastUpdateTime();
                    btVector3 unitTorque(0, 0, 0);
                    btScalar torqueMagnitude = 2.0f * deltaTime;

                    if (wParam == 'W') {
                        unitTorque.setY(1);
                    }
                    else if (wParam == 'S') {
                        unitTorque.setY(-1);
                    }
                    else if (wParam == 'D') {
                        unitTorque.setX(1);
                    }
                    else if (wParam == 'A') {
                        unitTorque.setX(-1);
                    }

                    //rb->ApplyImpulse(unitTorque * torqueMagnitude);
                }
                });
        }

        MSG msg = { 0 };
        while (true)
        {
            Game::GetInstance()->Update();

            if (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
                TranslateMessage(&msg);
                DispatchMessage(&msg);

                if (msg.message == WM_QUIT) {
                    break;
                }
                else if (msg.message == WM_KEYDOWN) {
                    /*
                    std::stringstream ss;
                    ss << "User pressed: ";
                    ss << (char)msg.wParam << std::endl;

                    OutputDebugStringA(ss.str().c_str());
                    */
                    Keyboard::GetInstance()->InputStarted(msg.wParam);
                }
                else if (msg.message == WM_KEYUP) {
                    Keyboard::GetInstance()->InputStopped(msg.wParam);
                }
            }
            else {
                const float t = Clock::GetSingleton().GetTimeSinceStart();
                const Mouse::Position mp = Mouse::GetSingleton(hWnd).GetPosition();

                std::ostringstream oss;
                //oss << "Time elapsed: " << std::fixed << t << "s";
                //oss << "Mouse Position: " << std::fixed << "(" << mp.x << ", " << mp.y << ")";
                oss << foo;
                SetWindowTextA(hWnd, oss.str().c_str());
            }
        }

        if (msg.wParam < 0) {
            throw new std::exception((const char*)GetLastError());
        }

        // return this part of the WM_QUIT message to Windows
        return msg.wParam;
    }
    catch (std::exception* e) {
        MessageBoxA(NULL, e->what(), "Error", 0u);
        return -1;
    }
}
