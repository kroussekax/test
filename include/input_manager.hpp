#include <GLFW/glfw3.h>
#include <unordered_map>

class InputManager {
public:
    static void Update(GLFWwindow* window) {
        for (auto& [key, state] : keyStates) {
            int currentState = glfwGetKey(window, key);
            keyStates[key].previous = state.current;
            keyStates[key].current = currentState;
        }
    }

    static bool IsKeyDown(int key) {
        return keyStates[key].current == GLFW_PRESS;
    }

    static bool IsKeyPressed(int key) {
        return keyStates[key].current == GLFW_PRESS && keyStates[key].previous == GLFW_RELEASE;
    }

    static bool IsKeyReleased(int key) {
        return keyStates[key].current == GLFW_RELEASE && keyStates[key].previous == GLFW_PRESS;
    }

private:
    struct KeyState {
        int current = GLFW_RELEASE;
        int previous = GLFW_RELEASE;
    };

    static inline std::unordered_map<int, KeyState> keyStates;
};
