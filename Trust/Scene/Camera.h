//
//  Camera.h
//  GLFW_OpenGL
//
//  Created by Lincoln Scheer on 3/27/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

# pragma once

#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

struct CameraPosition {
    glm::vec3 m_position;
    float m_pitch;
    float m_yaw;
    
    void set(glm::vec3 position, float pitch, float yaw) {
        m_position = position;
        m_pitch = pitch;
        m_yaw = yaw;
    }
};

const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 6.0f;
const GLfloat SENSITIVITY = 0.15f;
const GLfloat ZOOM = 5.0f;

class Camera {
public:
    glm::mat4 projection;
    glm::vec3 cam_position;
    float cam_yaw;
    float cam_pitch;
    
    Camera( glm::vec3 position = glm::vec3( 0.0f, 0.0f, 0.0f ), glm::vec3 up = glm::vec3( 0.0f, 1.0f, 0.0f ), GLfloat yaw = YAW, GLfloat pitch = PITCH ) : front( glm::vec3( 0.0f, 0.0f, -1.0f ) ), movementSpeed( SPEED ), mouseSensitivity( SENSITIVITY ), zoom( ZOOM )
    {
        this->position = position;
        this->worldUp = up;
        this->yaw = yaw;
        this->pitch = pitch;
        this->updateCameraVectors( );
    }
    
    Camera( GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch ) : front( glm::vec3( 0.0f, 0.0f, -1.0f ) ), movementSpeed( SPEED ), mouseSensitivity( SENSITIVITY ), zoom( ZOOM )
    {
        this->position = glm::vec3( posX, posY, posZ );
        this->worldUp = glm::vec3( upX, upY, upZ );
        this->yaw = yaw;
        this->pitch = pitch;
        this->updateCameraVectors( );
    }
    
    glm::mat4 getViewMatrix() {
        return glm::lookAt(this->position, this->position + this ->front, this->up);
    }
    
    void processKeyboard(Camera_Movement direction, GLfloat deltaTime) {
        GLfloat velocity = this->movementSpeed * deltaTime;
        
        if(FORWARD == direction) {
            this->position += this->front * velocity;
        }
        if(BACKWARD == direction) {
            this->position -= this->front * velocity;
        }
        if(LEFT == direction) {
            this->position -= this->right * velocity;
        }
        if(RIGHT == direction) {
            this->position += this->right * velocity;
        }
        if(UP == direction) {
            this->position += this->worldUp * velocity;
        }
        if(DOWN == direction) {
            this->position -= this->worldUp * velocity;
        }
    }
    
    void processMouseMovement(GLfloat xOffset, GLfloat yOffset, GLboolean constrainPitch = false) {
        xOffset *= this->mouseSensitivity;
        yOffset *= this->mouseSensitivity;
        
        this->yaw += xOffset;
        this->pitch += yOffset;
        
        // Up Down Constrints
        if(constrainPitch) {
            if(this->pitch > 89.0f) {
                this->pitch = 89.0f;
            }
            
            if(this->pitch < -89.0f) {
                this->pitch = -89.0f;
            }
        }
        
        this->updateCameraVectors();
    }
    
    void processMouseScroll(GLfloat yOffset) {
        /*
        if(this->zoom >= 1.0f && this->zoom <= 45.0f) {
            this->zoom -= yOffset;
        }
        
        if(this->zoom <= 1.0f) {
            this->zoom = 1.0f;
        }
        
        if(this->zoom >= 45.0f) {
            this->zoom = 45.0f;
        }
         */
    }
    
    GLfloat getZoom() {
        return this->zoom;
    }
    
    GLfloat getYaw() {
        return this->yaw;
    }
    
    GLfloat getPitch() {
        return this->pitch;
    }
    
    glm::vec3 getPosition() {
        return this->position;
    }
    
    void setYaw(float _yaw) {
        this->yaw += _yaw;
        this->updateCameraVectors();
    }
    
    void setPitch(float _pitch) {
        this->pitch += _pitch;
        this->updateCameraVectors();
    }
    
    void setPosition(glm::vec3 _position) {
        this->position.x += _position.x;
        this->position.y += _position.y;
        this->position.z += _position.z;
        this->updateCameraVectors();
    }
    
    void updateCameraVariables() {
        cam_position = getPosition();
        yaw = getYaw();
        pitch = getPitch();
    }
    
private:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    
    GLfloat yaw;
    GLfloat pitch;
    GLfloat movementSpeed;
    GLfloat mouseSensitivity;
    GLfloat zoom;
    
    void updateCameraVectors() {
        glm::vec3 front;
        front.x = cos(glm::radians(this->yaw) * cos(glm::radians(this->pitch)));
        front.y = sin(glm::radians(this->pitch));
        front.z = sin(glm::radians(this->yaw) * cos(glm::radians(this->pitch)));
        this->front = glm::normalize(front);
        this->right = glm::normalize(glm::cross(this->front, this->worldUp));
        this->up = glm::normalize(glm::cross(this->right, this->front));
        
        this->up = glm::normalize(this->worldUp);
    }
};

