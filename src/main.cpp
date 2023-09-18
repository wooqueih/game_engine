#include <iostream>
#include <string>
#include <cmath>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stb_image.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Application.hpp"
#include "Shader.hpp"
#include "Input.hpp"
#include "CameraSystem.hpp"
#include "Model.hpp"
#include "Scene.hpp"
#include "Id.hpp"
#include "CameraData.hpp"

static double deltaTime = 0.000001;
static float deltaTimef = (float)deltaTime;
static double fixedDeltaTime = 1/50;
static float fixedDeltaTimef = 1/50;
static double fixedTimeAccumulator = 0;
static Input& input = Input::getInstance();

int main() {
	Application app = Application::getInstance();
	app.init(1000, 1000, "grass");
	input.init(app.getWindow());

	IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(app.getWindow(), true);
    ImGui_ImplOpenGL3_Init();

	stbi_set_flip_vertically_on_load(true);

	Shader shader = Shader("shaders/vertex.glsl", "shaders/fragment.glsl");


	glEnable(GL_DEPTH_TEST);

	/*Camera camera(glm::perspective(glm::radians(80.0f), ((float)app.getWindowWidth()) / ((float)app.getWindowHeight()), 0.01f, 10000.0f));
	camera.m_position = glm::vec3(0.0f, 3.0f, 6.0f);*/

	Scene mainScene;
	Entity ground = mainScene.getSceneEntity().addChild();
	std::shared_ptr<Model> plane = ground.addComponent(Model("./models/ground_plane.glb"));
	std::shared_ptr<Transform> trans = ground.addComponent(Transform());
	trans->scale = glm::vec3(1.0f, 1.0f, 1.0f);
	trans->rotate(glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	trans->position = glm::vec3(-1.0f, 0.0f, 0.0f);
	glm::axis(trans->orientation);

	Entity player = mainScene.getSceneEntity().addChild();
	std::shared_ptr<Transform> playerTrans = player.addComponent(Transform());
	std::shared_ptr<CameraData> cameraData = player.addComponent(CameraData());
	cameraData->aspectRatio = ((float)app.getWindowWidth()) / ((float)app.getWindowHeight());
	cameraData->yFov = glm::radians(80.0f);
	cameraData->nearClippingDistance = 0.01f;
	cameraData->farClippingDistance = 10000.0f;

	std::shared_ptr<CameraSystem> cameraSystem = player.addSystem(CameraSystem(cameraData, playerTrans));

	bool active;

	double lastFrameTime = 0.0f;
	double thisFrameTime;
	//GAME LOOP
	while(!glfwWindowShouldClose(app.getWindow())) {
		thisFrameTime = glfwGetTime();
		deltaTime = thisFrameTime - lastFrameTime;
		deltaTimef = (float) deltaTime;
		lastFrameTime = thisFrameTime;
		//std::cout << thisFrameTime << std::endl;


        input.process();

		ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

		ImGuiIO& io = ImGui::GetIO();
		io.FontGlobalScale = 3;
		//ImFont* font1 = io.Fonts->AddFontFromFileTTF("/home/mischa/CLionProjects/untitled/cmake-build-debug/fonts/notosans.ttf", 26);

		float speed = 5.0f * deltaTimef;
		playerTrans->position += input.m_wasdMovement.z * speed * playerTrans->getForward();
		playerTrans->position -= input.m_wasdMovement.x * speed * playerTrans->getRight();
		//playerTrans->rotate(input.m_mouseMovement.y*deltaTimef, glm::vec3(1.0f, 0.0f, 0.0f));
		float rotY = input.m_mouseMovement.x*deltaTimef * input.m_mouseSensitivity;
		float rotX = input.m_mouseMovement.y*deltaTimef * input.m_mouseSensitivity;
		playerTrans->rotate(rotX, glm::vec3(1.0f, 0.0f, 0.0f));
		playerTrans->rotate(rotY, glm::vec3(0.0f, 1.0f, 0.0f));

		glClearColor(0.2f, 0.2f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glm::mat4 view = cameraSystem->getViewMatrix();
		shader.setUniformMatrix4fv("view", glm::value_ptr(view));
		glm::mat4 projection = cameraSystem->getProjectionMatrix();
		shader.setUniformMatrix4fv("projection", glm::value_ptr(projection));

		glm::mat4 model = trans->getMatrix();
		shader.setUniformMatrix4fv("model", glm::value_ptr(model));

		plane->draw(shader);

		ImGui::Begin("Test", &active, ImGuiWindowFlags_MenuBar);
		ImGui::SetWindowSize(ImVec2(0.0f, 0.0f));

		ImGui::Text("%4.2f fps", 1/deltaTimef);

		ImGui::InputFloat3("Position", glm::value_ptr(trans->position));
		ImGui::InputFloat4("Rotation", glm::value_ptr(trans->orientation));
		ImGui::InputFloat3("Scale", glm::value_ptr(trans->scale));
		auto tmp = (playerTrans->getEulerRotation() / M_PIf) * 360.0f;
		ImGui::InputFloat3("Camera rotation", glm::value_ptr(tmp));

		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(app.getWindow());
        glfwPollEvents();
    }
	ImGui_ImplGlfw_Shutdown();
	ImGui_ImplOpenGL3_Shutdown();
	ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}