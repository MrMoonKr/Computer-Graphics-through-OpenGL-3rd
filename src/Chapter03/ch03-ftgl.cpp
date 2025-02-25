#include <GL/glew.h>
#include <GL/freeglut.h>
#include <FTGL/ftgl.h>
#include <iostream>
#include <chrono>
#include <string>
#include <random>
#ifdef __linux__
#include <GL/glx.h>
#endif

FTGLPixmapFont* font;  // 폰트 객체
int frameCount = 0;
std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
double fps = 0.0;


// 랜덤한 float 값을 얻는 함수
float getRandomFloat( float min, float max )
{
    static std::default_random_engine engine{std::random_device{}()};
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(engine);
}

// 텍스트 렌더링 함수
void renderText( const char* text, float x, float y, float r, float g, float b ) 
{
    glColor3f( r, g, b ); // 텍스트 색상 설정
    glRasterPos2f( x, y );
    
    // 안티앨리어싱 비활성화 : 의미 없는듯
    //glDisable( GL_MULTISAMPLE );
    font->Render( text );
    //glEnable( GL_MULTISAMPLE );
}

// OpenGL 렌더링 콜백 함수
void display() 
{
    glClear( GL_COLOR_BUFFER_BIT );

    // 텍스트 색상 설정 및 렌더링
    renderText( "안녕하세요, OpenGL!", 100.0f, 200.0f, 1.0f, 1.0f, 1.0f ); // 흰색 텍스트

    int count = 50 ;
    float red = 0.0f ;
    float green = 0.0f ;
    float blue = 0.0f ;
    float x , y ;
    for ( int i=0 ; i < count ; ++i )
    {
        red = getRandomFloat( 0.0f, 1.0f );
        green = getRandomFloat( 0.0f, 1.0f );
        blue = getRandomFloat( 0.0f, 1.0f );
        x = getRandomFloat( 0.0f, 800.0f );
        y = getRandomFloat( 0.0f, 600.0f );
        renderText( "안녕하세요, OpenGL!", x, y, red, green, blue );
    }

    // FPS 텍스트 렌더링
    std::string fpsText = "FPS: " + std::to_string( static_cast<int>( fps ) );
    renderText(fpsText.c_str(), 10.0f, 580.0f, 1.0f, 1.0f, 0.0f); // 흰색 텍스트

    glutSwapBuffers();
    frameCount++;
}

void initVSync(int interval = 0 ) 
{
#ifdef _WIN32
    typedef BOOL(WINAPI * PFNWGLSWAPINTERVALEXTPROC)(int);
    PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;
    wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
    if ( wglSwapIntervalEXT )
    {
        wglSwapIntervalEXT( interval ); // V-Sync 비활성화
        std::cout << "V-Sync 설정 (Windows): " << interval << std::endl;
    }
    else 
    {
        std::cerr << "wglSwapIntervalEXT를 가져올 수 없습니다!" << std::endl;
    }
#elif defined(__linux__)
    typedef int (*PFNGLXSWAPINTERVALSGIPROC)(int);
    PFNGLXSWAPINTERVALSGIPROC glXSwapIntervalSGI = nullptr;
    glXSwapIntervalSGI = (PFNGLXSWAPINTERVALSGIPROC)glXGetProcAddressARB((const GLubyte*)"glXSwapIntervalSGI");
    if (glXSwapIntervalSGI) {
        glXSwapIntervalSGI(interval); // V-Sync 비활성화
        std::cout << "V-Sync 설정 (Linux): " << interval << std::endl;
    } else {
        std::cerr << "glXSwapIntervalSGI를 가져올 수 없습니다!" << std::endl;
    }
#endif
}

// 초기화 함수
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 배경색 검은색 설정

    // FTGL 폰트 로드
    font = new FTGLPixmapFont("./data/D2Coding-Ver1.3.2-20180524.ttf");
    if (font->Error()) {
        std::cerr << "폰트 로드 실패!" << std::endl;
        exit(1);
    }

    // 폰트 크기 설정
    //font->FaceSize(24);
    font->FaceSize(12);

    // V-Sync 비활성화
    initVSync(0);
}

// 창 크기 조정 시 호출
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}

// FPS 계산 및 출력 함수
void calculateFPS() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = currentTime - lastTime;
    if (elapsed.count() >= 1.0) {
        fps = frameCount / elapsed.count();
        frameCount = 0;
        lastTime = currentTime;
    }
    glutPostRedisplay();
}

// 메인 함수
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    int windowWidth = 800;
    int windowHeight = 600;

    // 화면 크기 가져오기
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);

    // 윈도우를 화면 중앙에 배치
    int windowPosX = (screenWidth - windowWidth) / 2;
    int windowPosY = (screenHeight - windowHeight) / 2;

    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(windowPosX, windowPosY);
    glutCreateWindow("FTGL 한글 출력 예제");

    init();

    lastTime = std::chrono::high_resolution_clock::now();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(calculateFPS);

    glutMainLoop();
    return 0;
}


