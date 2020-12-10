#include "GamePCH.h"

#include "Objects/Player.h"
#include "Objects/PlayerController.h"
#include "Game.h"

Player::Player(fw::GameCore* pGameCore, PlayerController* pPlayerController, std::string name, vec2 pos, fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec4 color)
    : fw::GameObject( pGameCore, name, pos, pMesh, pShader, pTexture, color )
    , m_pPlayerController( pPlayerController )
{
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    float speed = 2.0f;

    vec2 dir;

    if( m_pPlayerController->IsHeld( PlayerController::Mask::Up ) )
    {
        dir.y += 1;
    }
    if( m_pPlayerController->IsHeld( PlayerController::Mask::Down ) )
    {
        dir.y += -1;
    }
    if( m_pPlayerController->IsHeld( PlayerController::Mask::Left ) )
    {
        dir.x += -1;
    }
    if( m_pPlayerController->IsHeld( PlayerController::Mask::Right ) )
    {
        dir.x += 1;
    }

    m_UVScale = vec2( 64.0/1024.0, 64.0/512.0 );
    m_UVOffset = vec2( 780.0/1024.0, 383.0/512.0 );

    //dir.Normalize();

    m_Position += dir * speed * deltaTime;

    // Deal with collision with the environment.
    {
        // Query Game for environment limits.
        //static_cast<Game*>( m_pGameCore )->

        // Apply those limits.
        if( m_Position.x > 8 )
        {
            m_Position.x = 8;
        }
    }

    (this->*m_pCurrentStateFunction)( deltaTime );
}

void Player::AIState_Idle(float deltaTime)
{
    ImGui::Text( "Idle" );
    m_IdleTimer += deltaTime;
    if( m_IdleTimer > 1 )
    {
        m_pCurrentStateFunction = &Player::AIState_Shaking;
        m_IdleTimer = 0;
    }
}

void Player::AIState_Shaking(float deltaTime)
{
    ImGui::Text( "Shaking" );
    m_Position.x += (((rand()%RAND_MAX)/(float)RAND_MAX) * 2 - 1) * 0.05f;
    m_Position.y += (((rand()%RAND_MAX)/(float)RAND_MAX) * 2 - 1) * 0.05f;

    m_ShakingTimer += deltaTime;
    if( m_ShakingTimer > 1 )
    {
        m_pCurrentStateFunction = &Player::AIState_Idle;
        m_ShakingTimer = 0;
    }
}
