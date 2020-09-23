#pragma once

class Game : public fw::GameCore
{
public:
    Game(fw::FWCore* pFramework);
    virtual ~Game();

    void Init();
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

protected:
    fw::ImGuiManager* m_pImGuiManager = nullptr;

    fw::ShaderProgram* m_pShader = nullptr;
    fw::Mesh* m_pMeshHuman = nullptr;
    fw::Mesh* m_pMeshAnimal = nullptr;

    std::vector<fw::GameObject*> m_Objects;
};
