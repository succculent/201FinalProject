This is the CSCI 201 Final Project for -  

Jason Yik, jyik@usc.edu

Nick Chen, nickchen@usc.edu

Ada Toydemir, toydemir@usc.edu

Haoda Wang, haodawan@usc.edu

Kai-Chin Hsu, kaichinh@usc.edu

Lauren Shen, laurenys@usc.edu




# Project Proposal:

  We plan to create a website/game application which can in essence be used as a malicious virus.
We will have two types of users on the app: guests and authenticated users. An authenticated user
may invite guests to create accounts on the website. A guest will enter the website and see a
download link for a simple loot box / clicker game. The guest will download the game using this
link, but really the game acts as a carrier for a virus that we will write. When the guest plays
the game, the virus spawns off a thread on the guest’s CPU which will use Bitcoin API in order to
generate hashes to mine Bitcoin. The results of these functions will be sent over to the
authenticated user who invited this guest such that the guest is mining Bitcoin for the authenticated
user. From the same website, authenticated users will be directed to a page which will show them
real-time statistics of their guests’ mined hashes. An authenticated user will have the power to
promote a guest to an authenticated user, so that the promoted user will be able to invite their own
guests and make them mine for him. The server will have threads running for each guest and authenticated
user in order for cross communication to happen between them.



# High-Level Requirements: 

  We need to create a bitcoin mining operation with a game interface. First we need to create a website that serves two functions depending on whether the user is authenticated or not. Users will be asked to register themselves, then login and download the game. Once downloaded and run, the program will force the user’s machine to mine hashes for bitcoin for that user’s specific authenticated user. The program itself is a simple carrier game that the unauthorized user will play as the bitcoin miner works secretly in the background. 
  When an authenticated user logs into the website, they will be able to view the bitcoin statistics. ​from all the different clients. Only users who login using administrator details will be able to see this statistics page. 

## Total Time: 39 Hours

## Website Front End - 6 Hours

-   Front page is an info page with a login and register page

-   The interface for guest users should consist of 2 pages.

-   The first page is the registration page which will have a form asking the user for a username and password. 

-   Once the form is validated that the authenticated user exists, the guest should be redirected to a page with a simple download button that will download the game/virus to their computer.

-   The interface for authenticated users should consist of 2 pages.

-   The first page should be a login page, with fields for username and password, and a login button.

-   Once the form is validated, if the user is an administrato and the authenticated user's credentials are correct, the user should be redirected to a page with a table that shows their guest user's mining calls. The table should have columns for the guest user's username, the value of the hash, and the time at which the hash was received, with each row being a different hash.

-   The frontend will run off our website domain, myvir.us

## Server / Database Connection - 2 Hours

-   The connections to our database will be done through a servlet.

-   We will have to access it for validation when user is logging in.

-   We will have to modify it for adding a new user when registering.

-   We will have to modify it when the users are calculating hashes for the bitcoin miner, these hashes will be added to the table.

## Server / Front End Connection - 1 Hours

-   The pages which need data from the database - the statistics page and the verification pages for login - will need to connect to the server for information / validation. The server will send back responses for statistics or for validation.

## Server / Threading - 3 Hours

-   The server will multi-thread by listening for UDP packet and spawn another thread to add information from the packet to the database 

## Server / Virus Connection - 5 Hours

-   Virus will open with a POST request to the server containing a randomly generated, unique, and persistent UUID, which will then be used to identify the machine from that time on.

-   The server will then respond with a hash for the virus to calculate.

-   Once calculated, the hash is then returned to the server using another POST request.

## Database - 1 Hour

-   The database should have 3 tables: A User table, Password table, and Hashes table.

-   The User table is used to check whether a user is authenticated or not. The keys will be userID, username, admin status. 

-   The Password table holds the passwords of each user. The keys will be pass_id, user_id, and password.

-   The Hashes table holds data for the hashes computed by the guest users. The keys will be hash_uuid, compute_time, address, received_time, result

## Game Engine Set Up & Resource Search - 3 Hours

-   Our game will use an existing graphics library to create a simple game engine. 

-   The created engine should be able to Load/Unload save files, handle mouse inputs, importing sprites, basic player stats, keep track of time, and running a basic game loop.

-   We also need to find various game sprites such as item sprites, loot box sprites, and a background.

-   Game should also write a save file to the computer in the form of a text file that includes user collected items, and user balance. On load, the game will load the save file of the user that is currently mining (based on who is logged in).

## Game Programming (Virus Carrier) - 6 Hours

-   Game will install the virus

-   The user should be able to click a button to gain currency. There should also be a counter for how much currency the user currently has. 

-   The screen should display three different loot boxes that function the same but have different items and balance. Loot boxes should contain "novelty" items and potential to earn more currency or passive currency. 

-   When a box is clicked, it will determine whether or not the player has enough currency to buy the specific loot box. If the player does not have enough currency, then an error message should be displayed.

-   Upon successful purchase of the lootbox, the animation of the loot box opening should play and an item should be revealed. The item is either a novelty item (which gets added to the inventory) or it is currency which gets added to the players wallet.

## System Virus - 4 Hours

-   The system virus will be implemented in a version of LLVM libc++. This provides both an easy way to hook into any existing program, and due to the portable nature of shared libraries can be quickly moved to new systems as well.

-   In order to ensure that the virus does not break bare-metal system components, the main program, as well as the virus, will run in a virtual machine on QEMU/libvirt.

-   The virus will add it's behaviour into all calls to thread and spawn off a new thread which runs the bitcoin miner each time the function is called.

## Bitcoin Miner - 8 Hours

-   The bitcoin miner will be implemented in Python, and will be called by the System Virus whenever thread is called.

-   Every thread call by the System Virus will request a new hash from the API.

# Detailed Design:

## Website Front-End

-   Website Flowchart

![](https://lh3.googleusercontent.com/A1wYl2aFmWfH7wYIK9mHJTop_afnw_SyIWH04BWRMbNl_58doCmz5eJL0m_4G1ck0py2dGBIXiIwGZclz_JwBAkP4Qq-PIU4Sju-Hr8cWoIumL0IWPwDWwMknaNtosEpK_dh05L1)

-   The logo on each page will be replaced with:

-   Home Page

-   The Home page is a static page that will look something like this:

![](https://lh6.googleusercontent.com/U81WjaGyomZQmpqWARdQ1NMIOdWL8Tb_CIHS9sz0GWMIvLQf_eicYqusL9jS950yFj4iyTt7HrIii2qkD8YXo3LYtDryTePVHnlZ1d1D1BtSjD7ndyZF2ACvZG3RqN9BOoF8rZi1)

-   Clicking "Login" will redirect the user to the login page

-   Clicking "Register" will redirect the user to the signup page

-   Clicking "About the Game" will redirect the user to the game instructions page

-   Login Page (login.jsp)

-   The Login page should look like:

![](https://lh6.googleusercontent.com/F4dLICEQxuLEQfYK9eoD50d5WDOEcl93F4x_bC4c-WDRum05pDczIpVZOrrM4qxLTG1Nqkcktjvib9ZS_pPeoH34rOIJEFlvVxlFAF89jTCpOQP7XzeePmr9xDMeSI0hPHczrkXq)

-   The form will have a "onsubmit" event that executes a JavaScript function validate() when the form is submitted. The function returns a Boolean value depending on whether the registration was successful, submitting if the value is true and staying on the page otherwise.

-   This function will use AJAX and create an XMLHttpRequest object, sending the parameters "username" and "password" to a separate Java Servlet "ValidateLogin" via a "GET" request

-   "ValidateLogin" will have a service function that retrieves the parameters and accesses the table of Users and Passwords in the MySQL database on the GCP through the jdbc: mysql driver

-   Specifically, the function checks for the following cases by checking the parameters against table entries in the database

-   Username does not exist

-   Output error message below username field: This user does not exist 

-   Username exists but incorrect password

-   Output error message below password field: Incorrect password

-   Username exists and correct password

-   Set the session variable as the current user

-   Return true in validate() and redirect the user to "download.jsp"

-   Register Page (register.jsp)

-   The Register page should look like:

![](https://lh6.googleusercontent.com/KrAVwuda0hjeYGBok_MbIW1k8g0ndDmMD5ANVzSjToK7u1lF9GM3qLGwgOLVuKI5YIeaKWdbNK5qOfg_MtbT8KNvZWqdlX8J5L_xzlIbpG0YLjmDO0UoeZLj1hPeREBkkO20zE9L)

-   The form will have a "onsubmit" event that executes a JavaScript function validate() when the form is submitted. The function returns a Boolean value depending on whether the registration was successful, submitting if the value is true and staying on the page otherwise.

-   Similar to the login page, this function will use AJAX and create an XMLHttpRequest object, sending the parameters "username", "password" and "confirm_password" to a separate Java Servlet "ValidateRegister" via a "GET" request

-   "ValidateRegister" will have a service function that retrieves the parameters and accesses the table of Users and Passwords in the MySQL database on the GCP through the jdbc: mysql driver

-   Specifically, the function checks for the following cases

-   Passwords do not match

-   Output error message below username field: Passwords must match 

-   Username exists 

-   Output error message below password field: Username already exists

-   Username exists and passwords match

-   Pass parameters to a function within the servlet called addNewUser(string username, string password), where a new entry is added to both the Users and Passwords tables using the SQL INSERT INTO statement

-   Set the session variable as the current user - if registration is successful, the user is automatically logged into this new account

-   Return true in validate() and redirect the user to "download.jsp"

-   Statistics Page (statistics.jsp)

-   The Statistics page should look like: 

![](https://lh5.googleusercontent.com/fvyabZGcarE7pc3JLy8v6y-bJKiA3R9kDMFoC4etS4G11TBTTDOQ2-anHJx1dD6VCO0DDAdhNIyffir93zbMd5gy4sQEctKDKkZf8HOAPc__ShwGRVx7yMbPoXZMqdfGNwmbFLOB)

-   This page is only available to the administrators

-   Clicking "Refresh" should update the table statistics

-   The button will have an "onClick" event that executes a JavaScript function refreshPage() that forces the page to reload from the server

-   This function uses an AJAX call, creating another XMLHttpRequest object that makes a "GET" request to a separate Java Servlet "Statistics" that will return an updated stats table and update the webpage

-   Clicking "Logout" should redirect the user to the Home page

-   Download Page (download.jsp)

-   Page contains a single link to download the game:

![](https://lh4.googleusercontent.com/mLDXwXQ6WOA1eaX-1fBDMyiJ2S8i5U6nT8Ru6PE_X_kiUxBzJPOub8iIiCeCszF_dY_rwz-dJMMysvwHDLV8HAy6SafKV2GXuLcibhgJiPSfdlVVzBJfuxmigCkILdti9SG1RANC)

-   Game Instructions Page (gameinfo.jsp)

-   Page contains instructions for the game: 

![](https://lh6.googleusercontent.com/roqA1mNdA-hO8VCFKKVx5k-97th14Mfl5_jU6nLFm9iu3M6-2El95Heav1nRs9pzzbx1gyulcGRjQF-F-POOjsGVuvlxqt8ns44f3ei9saEy9QZT5Yt9c3TLULOKPz7pSN3SfME-)

## Game

Main Function

-   Checks for the existence of a libc++.so in /usr/lib. If missing, run the following function

-   Create a new libc++.so from program memory and overwrite old libc++

-   Creates a Game object. Game object should call "Initialize". The game object will call a Loop() and continue looping until an exit state is created through either the user exiting or the program aborting.

![](https://lh6.googleusercontent.com/BgGIQCBGB7YBPlb2xVdEhaOyDOqOYolSt9yCpSYYkp8aPzRkSsPaCu48oSRrvSQeTyrN8UHs90aDo2vXaWyQ2117aY2ZWg7e6kPvRfW2tGcAHwAY-UmkcwEBLus64nRIjJA5osc7)

Chest Sprite Source: <https://opengameart.org/content/pixel-chest-and-coin>

-   The game is a simple carrier cookie clicker like game.

-   Loot box simulator where user gains "currency" by clicking a button. Users will have the option to purchase 3 different tiers of loot boxes,  Normal, Ultra, and Prestige.

![](https://lh5.googleusercontent.com/wI5fOmV5rZ7B4o80hSXmyeMkEg-PKnFr2cr9TTK31E6oclNLHnIBkifALpZnKQqSrbcGfZASCVCoe6lZRfGw7YMVw4OS1d-vGd-HsPKHqSolducPJgTKN0861FTE-0kYNk71fd1h)

-   GAME_Actor

-   enum State

-   need 3 states, EActive, EPaused, EDead

-   Variables:

-   protected State mState

-   protected Vector2 mPosition

-   protected float mScale

-   protected float mRotation

-   protected SpriteComponent* mSprite

-   Actor(class Game* game)

-   Set mGame to game

-   Set mState to EActive

-   Set mPosition to the zero vector

-   Set mScale to 1.0f

-   Set mRotation to 0.0f

-   Add this actor the game

-   set mSprite to nullptr;

-   ~Actor()

-   Remove this actor from the game by calling mGame->Remove(this)

-   delete the mSprite pointer

-   void Update(float deltaTime)

-   if the state of this class is active, call UpdateActor()

-   void UpdateActor(float deltaTime)

-   if the mSprite is not null update the sprite

-   void ActorInput (const Uint8* keyState)

-   if mSprite is not null, ProcessInput based on Sprite 

-   void SetSprite (SpriteComponent* sprite)

-   setter function for the mSprite variable

-   SpriteComponent* GetSprite()

-   getter function for the mSprite variable 

-   GAME_Component 

-   Component(Actor* owner)

-   sets Owner of the component to the actor

-   GAME_Player extends GAME_Actor

-   Variables

-   int balance

-   vector <Item*> inventory

-   int getBalance()

-   int subtractBalance(int coin)

-   void addToInventory(Item* item)

-   void getItem(String name)

-   GAME_SpriteComponent extends GAME_Component 

-   Variables

-   protected SDL_Texture* mTexture;

-   Texture object of the sprite

-   protected int mDrawOrder

-   protected int mTexWidth

-   protected int mTexHeight

-   All variables also need getters

-   SpriteComponent(Actor* owner, int drawOrder)

-   Need to call Component Constructor

-   Set mTexture to nullptr

-   mTexWidth set to 0

-   mTextHeight set to 0

-   mDrawOrder to drawOrder

-   Call the owner of this object and AddSprite 

-   ~SpriteComponent()

-   Delete this sprite from the game sprite vector

-   void Draw(SDL_Renderer* renderer)

-   If this SpriteComponent has an mTexture initialized (not null)

-   Create a SDL_Rect called r

-   Set the width of the rectangle through static_cast<int> to be the mTexWidth*mOwner->GetScale()

-   Set the height of the rectangle through static_cast<int> to be the mTexHeight*mOwner->GetScale()

-   Set the x-position of the rectangle through static cast to be (mOwner->GetPosition().x - rw/2)

-   Set the y-position of the rectangle through static cast to be (mOwner->GetPosition().x - rw/2)

-   Call SDL_RenderCopyEx with our renderer, texture, rectangle, and angle to set the position to our texture.

-   void SetTexture(SDL_Texture* texture)

-   Sets our variable mTexture to the texture passed in

-   Call SDL_QueryTexture to query our texture

-   GAME_LootBox extends GAME_Actor

-   Variables

-   private int cost 

-   This is the cost of the box

-   private int numInventory

-   This is the number of this box they currently own. By default it is set to zero. 

-   private String name

-   Name of the loot box

-   LootBox(String n, int c )

-   This is the constructor

-   Set the name of this box to n 

-   Set the cost of this box to c 

-   private Vector<Items> drops

-   This is a vector/array of all possible drops from the loot box. There may be  duplicates of the same item in the array as this will be the way that we "balance the item drop rate"

-   private vector <Images> sprite

-   This is a vector/array containing each individual frame of the lootbox.

-   sprite[0] should be  

-   void setSprite(SpriteComponent* sprite)

-   A function that sets the sprite 

-   private Items openBox(int random) 

-   This is a method that "opens" the loot box. The loot box will play the animation 

-   public int purchaseBox(Player* player)

-   This is a method that takes in the player status and checks to see whether or not the player has enough currency. 

-   If the player has enough currency, deduct the cost of this loot box from the players wallet and increment the numInventory for the specific box. 

-   protected setCost(int c)

-   Sets the cost of this specific type of box

-   protected increment_numInventory()

-   Increments the number of this specific type of loot box 

-   protected setName(String n)

-   Sets the name of the lootbox

-   GAME_Game (Class)

-   This is the main "game engine". The code will be referencing an existing game engine from a different class (ITP 380) 

-   Required libraries: 

-   SDL/SDL_image 

-   Graphics library in C++

-   fstream

-   iostream

-   algorithm

-   Include the following classes

-   LootBox

-   Actor

-   SpriteComponent

-   Variables:

-   const int WINDOW_WIDTH 

-   Set these values for window height

-   const int WIDOW_HEIGHT

-   Set these values for window height

-   SDL_Window *window

-   Keep track of our window

-   SDL_Renderer * renderer

-   Keep track of our render

-   unsigned int lastTime = 0

-   Keep track of the last recorded time 

-   unsigned currentTime 

-   Keep track of the current time being processed by our engine

-   float deltaTime

-   The time in change between lastTime and currentTime used to calculate FPS distance and frames

-   bool gameRunning

-   A boolean that checks if the game is still running

-   vector <Actor*> mVector

-   A vector of all actor type items in our game

-   SDL_Texture* background

-   our background texture

-   unordered_map<string,SLD_Texture*> sprites

-   An unordered map that organizes our textures by their name

-   vector <SpriteComponent*> mSprites

-   a vector of all the sprites that are loaded into our game

-   Game()

-   Constructor is empty

-   bool Initialize()

-   Initialize a random number generator

-   Sets initial variables of lastTime and currentTime by using a method to get the current time

-   This function should also call the LoadData() function

-   Private const int WINDOW_WIDTH

-   Width of the window size we are using, default is 1024

-   Private const int WINDOW_HEIGHT 

-   Height of the window we are using, default is 

-   Load video/audio/image support

-   Attempts to initialize the SDL library for video and audio (?) 

-   If this fails, exit and log that it was unable to initialize with SDL_Log

-   Create a window and store it in a variable called window

-   window = SDL_CreateWindow(name of window, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);

-   Create a renderer and store it in a variable called renderer

-   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

-   Load support for PNG images by setting an int called flags equal to "IMG_INIT_PNG" and passing that into another function called "IMG_INIT(flags)" which will be stored in an int called initted.

-   Check to make sure that that the initialization of image support worked by using bitwise & on flags and initted and if it does not equal flags, it has failed to start image support

-   Print out a message of the failure and quit the program. 

-   If window or the renderer is null, they have also failed to initialize properly, return zero and quit the program.

-   void Shutdown()

-   Calls UnloadData()

-   This function shuts down the game by making sure all memory is deleted properly and etc.

-   Call IMG_Quit(), which frees memory taken up by images

-   Call SDL_DestoryRenderer()

-   Call SDL_DestroyWindow()

-   Call SDL_Quit()

-   void Loop()

-   While the gamestate is still active (program is still active) the game should ProcessInput, UpdateGame, and GenerateOutput. These will each be a method to call (ProcessInput(), UpdateGame(), GenerateOutput())

-   void ProcessInput()

-   This function should get the last event that occurred (in our case mouse clicks or escape buttons) 

-   If the player has indicated to quit, set the gamestate to false

-   void UpdateGame()

-   Updates current time to a variable called currentTime

-   Calculates the change in time and stores it in deltaTime

-   currentTime - lastTime /1000.0f 

-   This will store the time as units of seconds 

-   if the change in the last time is greater than 0.05 set the change in time to 0.05

-   Get all items currently active actors and update all of them 

-   Active actors are stored in a vector named mVector

-   If the actors are in dead state after being updated, add them to another vector named "dead" so that we can delete them 

-   Loop through the dead vector and call RemoveActor for any dead elements

-   void GenerateOutput()

-   Set up background renderer settings by calling SDL_SetRenderDrawColor

-   Clear the renderer from the previous frame by calling 

-   SDL_RenderClear

-   Loop through all sprites in the game and call the Draw() method

-   Present the current frame by calling SDL_RenderPresent()

-   void AddActor(Actor* a)

-   Adds actors to our game so we can keep track of all actors that we need to use for the game

-   Pushes back elements to the mVector vector. 

-   void RemoveActor(Actor *a)

-   Removes dead actors from our vectors and deletes their memory

-   Erases the actor from mVector vector by using the find function from the algorithm STL. 

-   void LoadData()

-   Loads all the components we need for the game. 

-   Create a new Actor pointer known as Background

-   Create a new SpriteComponent known as background and pass in the Background Actor and Draw Order of 1

-   Call SetTexture on back to set the texture

-   Use GetTexture() to get the texture associated with the file location/name

-   Set Background Actor to have a SpriteComponent of back by calling SetSprite(back)

-   Set the location of this sprite by calling SetPosition

-   Position is assigned as Vector2 Type

-   The center coordinate is (512,385)

-   Create all the items by calling their respective constructors and them to our mVectors by calling AddActor()

-   We need to create the following items as actors

-   Loot Boxes

-   Redeemable Items

-   void UnloadData()

-   Remove all items from mVector by calling pop_back()

-   This will automatically delete all items

-   SDL_Texture* GetTexture(string fileName)

-   This method will return a texture type of object so we know what the texture is

-   if the sprite has previously been loaded in our game, look for it in our sprite vector and return that element

-   Otherwise create an SDL_Surface pointer called image and call IMG_Load with the file name.

-   If the SDL_Surface is NULL, this means our texture was not found. Print an error message and return 0

-   If there is no error, create a temporary SDL_Texture pointer named background and use SDL_CreateTextureFromSurface() to initialize background. 

-   Add this temporary SDL_Texture to the sprites array then return background

-   void AddSprite(SpriteComponent* sprite)

-   Adds the sprite component to the mSprites vector then sorts it 

-   void RemoveSprite(SpriteComponent* sprite)

-   Erases the sprite from the game and mSprite vector

-   GAME_Item extends Actor

-   int chance

-   String description

## Bitcoin Miner

-   The Bitcoin Miner will be a client-side program which communicates with the API and the server.

-   The Server side of the Bitcoin Miner will be a thread hosting a UDP connection listening for messages from the Clients and then create another thread to forward that info to the database through a Server-side initConnection(). It will be written in Java.

-   The Client side of the Bitcoin Miner will have a thread listening for system call to the C++ threads library through a Client-side initConnection(). Upon receiving a system call, it'll make a GET request to the blockchain API through getHash(), which will return the current hash to be computed. The Client then makes 42 attempts to solve the hash through tryHash(). Regardless of whether the hash was solved, the result is sent to the Server through sendClient(). It will be written in Client.

CLIENT_BitcoinMiner

-   Written in Python

-   initConnection()

-   Will open a thread listening for system calls to C++ threads library

-   Upon receiving a system call, it'll make appropriate calls to getHash(), tryHash(), and sendClient()

-   getHash()

-   Will use this API: <https://www.blockchain.com/api/q> to get a hash to calculate

-   Returns the hash returned by api

-   tryHash()

-   Will use the SHA-256 algorithm to attempt to calculate the hash

-   This will attempt to calculate the hash 42 times

-   if this is unsuccessful, it will return fail

-   If this is successful, it will return the calculated hash

-   sendClient()

-   Sends the calculated hash or the failed attempt  to the Server through a GET request

SERVER_BitcoinMiner

-   Written in Java

-   initConnection()

-   Initiates connection to the Bitcoin mining pool API, and starts listening for messages from the Client.

-   When a message is received from the Client, the information is parsed and sent to the Database

## Virus

-   Overrides common functions by acting as a legitimate libc++

-   Clone sources from https://github.com/llvm-mirror/libcxx/blob/master/include/thread

-   Spawn a new C thread in the thread() constructors which will run the Python script using embedded Python

-   Installation described in the main loop

-   Each call of a function from thread.h also calls the client-side bitcoin miner as a separate pthread before running the actual function call

## Server

![](https://lh4.googleusercontent.com/zngetDZkFeCh4Yzx9oNwwZaYQiEJeTVsyeXrCoLYGAXp9RaPizQ1GBVCCKPtpVSUSQIoGeNj_FqpSEfwA8JJpA89Ar9W6n2IZ9CLL9Os25HAfuTjWo-pPzNL5ZfPCtzle1rPIzVD)

SERVER_ValidateRegister extends HttpServlet

-   Java file which uses JDBC to connect to the database

-   Accepts a GET request with the parameters username, password, and confirm_password

-   Returns a response string based on any error it finds (detailed above), otherwise returns an empty string

-   If the registration is successful

-   addNewUser(string username, string password)

-   Insert the username and password into the database

SERVER_ValidateLogin extends HttpServlet

-   Java file which uses JDBC to connect to the database

-   Accepts a GET request with the parameters username, password

-   Returns a response string based on any error it finds (detailed above)

-   If the login is successful, return an empty string

SERVER_Statistics extends HttpServlet

-   Java file which uses JDBC to connect to the database

-   Returns a response string in JSON format with all of the statistics from the database

SERVER_VirusConnector

-   Java file which runs on GCP

-   Spawns a PacketServer thread on initialization

SERVER_PacketServer extends Thread

-   Will open a UDP WebSocket on Port 42069

-   The socket continually listens for UDP packets from the virus.

-   Upon arrival of a packet, spawn a HashAccept thread with the packet's information

SERVER_HashAccept extends Thread

-   Takes packet information as a parameter

-   Uses JDBC to add the packet's information into the database

# Requirements

## Hardware Requirements

-   Any x86_64 PC supporting the AVX1 instruction set

## Software Requirements

-   GNU/Linux distribution running with a libstdc++

-   For testing, a virtual machine running an install of Slackware Linux in QEMU over libvirt

-   The server and database will be hosted on Google Cloud Platform

## Database Schema

![](https://lh5.googleusercontent.com/ebg0z1WBavqhb-KOPy0QpYh5kU0MiStdu7GB21VGzVqFwSobZLtFWsTw4-167YfRS14i5vTuREXRIhI7D_bvtBRat_f0m-1sGlazL9i2x3YZ0DlchSGHzpLl_hCfD7OgmhCgqKqF)

# Deployment Documentation:

Please follow this document for instructions on deploying our programs onto a live environment. It needs to include step-by-step instructions of what to do to take the code from Eclipse and deploy it. This will most likely consist of some other configurations also (i.e. outside libraries, server settings, Java download/install, etc.)

In addition to the deployment document, submit your requirements, specifications, detailed design document, testing document/code, and updated code with any changes clearly delineated using a feature such as Track Changes.

-   Set up the database on a Google Cloud SQL instance

-   Push the application to a live Tomcat server on Google Cloud

-   Make sure all JDBC connections are set up

-   Set up connection to domain [www.myvir.us](http://www.myvir.us) and link the application to it with the Tomcat configuration

-   Test and make sure that the application is working correctly by interacting with the website, downloading the game, running the game, and activating the virus script within a VM.


