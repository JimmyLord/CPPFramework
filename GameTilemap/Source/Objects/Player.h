#pragma once

class PlayerController;

class Player : public fw::GameObject
{
    typedef void (Player::*AIStateFunction)(float deltaTime);

public:
    Player(fw::GameCore* pGameCore, PlayerController* pPlayerController, std::string name, vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec4 color);
    virtual ~Player();

    virtual void Update(float deltaTime) override;

    void AIState_Idle(float deltaTime);
    void AIState_Shaking(float deltaTime);

protected:
    PlayerController* m_pPlayerController = nullptr;

    AIStateFunction m_pCurrentStateFunction = &Player::AIState_Idle;

    float m_IdleTimer = 0.0f;
    float m_ShakingTimer = 0.0f;
};
