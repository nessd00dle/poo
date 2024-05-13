#pragma once
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <string>

// Estructura para representar una textura
struct Texture {
    GLuint id;
    int width;
    int height;
};

// Clase para manejar un sprite animado
class AnimatedSprite {
public:
    AnimatedSprite(const std::vector<std::string>& texturePaths) {
        // Cargar todas las texturas proporcionadas
        for (const auto& path : texturePaths) {
            Texture texture;
            loadTexture(path, texture);
            textures.push_back(texture);
        }
    }

    void draw(float x, float y) {
        // Dibujar el sprite actual en la posición especificada
        glBindTexture(GL_TEXTURE_2D, textures[currentTexture].id);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex2f(x, y);
        glTexCoord2f(1, 0); glVertex2f(x + textures[currentTexture].width, y);
        glTexCoord2f(1, 1); glVertex2f(x + textures[currentTexture].width, y + textures[currentTexture].height);
        glTexCoord2f(0, 1); glVertex2f(x, y + textures[currentTexture].height);
        glEnd();
    }

    void update() {
        // Lógica de actualización para animar el sprite
        currentTexture = (currentTexture + 1) % textures.size();
    }

private:
    std::vector<Texture> textures;
    int currentTexture = 0;

    void loadTexture(const std::string& path, Texture& texture) {
        // Aquí implementa la carga de textura desde el archivo 'path'
        // Este es un ejemplo básico, deberías usar una librería de carga de imágenes
        // como SOIL, stb_image u otra similar para cargar texturas desde archivos.

        // Ejemplo de generación de una textura temporal
        glGenTextures(1, &texture.id);
        glBindTexture(GL_TEXTURE_2D, texture.id);

        // Configuración de la textura (ejemplo: textura de cuadro blanco)
        unsigned char pixel[] = { 255, 255, 255, 255 }; // píxel blanco
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixel);

        // Asignar tamaño arbitrario para el ejemplo
        texture.width = 100;
        texture.height = 100;
    }
};

// Variables globales
AnimatedSprite sprite({ "texture1.png", "texture2.png", "texture3.png" });

// Función de renderizado
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujar el sprite animado en la posición (100, 100)
    sprite.draw(100, 100);

    glutSwapBuffers();
}

// Función de actualización
void update(int value) {
    sprite.update(); // Actualizar la animación del sprite
    glutPostRedisplay();
    glutTimerFunc(100, update, 0); // Llamar a la función update cada 100 ms
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Animated Sprite");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1, 1);

    glutDisplayFunc(renderScene);
    glutTimerFunc(0, update, 0); // Iniciar la función update inmediatamente

    glutMainLoop();
    return 0;
}