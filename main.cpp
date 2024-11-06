#include<iostream>
#include<ctime>
#include <sstream>
#include<fstream>
#include<iomanip>
using namespace std;
class gameNode
{
private:
    /* data */
public:
    gameNode* left;
    gameNode* right;
    string gameName;
    string game_Id;
    string developer;
    string publisher;
    float sizeOfFile;
    int downloadCount;
    gameNode(){
        left = nullptr;
        right = nullptr;
    }
    gameNode(stringstream &s){
        left = nullptr;
        right = nullptr;
        string temp;
        getline(s,game_Id,',');
        getline(s,gameName,',');
        getline(s,developer,',');
        getline(s,publisher,',');
        getline(s,temp,',');
        stringstream c(temp);
        c >> sizeOfFile;
        getline(s,temp,',');
        downloadCount = stoi(temp);
    }
    ~gameNode(){}
};
class GameNodeTree{
    public:
    gameNode *root;
    GameNodeTree(){
        root = nullptr;
    }
    void deleteTree(gameNode*& g1){
        if(g1 == nullptr){
            return;
        }
        else{
            deleteTree(g1->left);
            deleteTree(g1->right);
            delete g1;
            g1 = nullptr;
        }
    }
    ~GameNodeTree(){
        deleteTree(root);
        // cout << "Game Node Tree Desctruction Done" << endl;
    }
    void insertInGameTree(gameNode*&,gameNode*&);
    void inorder(gameNode*);

    void showGameDetails(gameNode*& root,string id);
    
};

void GameNodeTree :: insertInGameTree(gameNode*& Node,gameNode*& newNode){
    if (Node == nullptr){
        Node = newNode;
        return;
    }
    else{
        if ( newNode->game_Id > (Node->game_Id) )
        {
            insertInGameTree(Node->right,newNode);
        }
        else if ( (newNode->game_Id) < (Node->game_Id) )
        {
            insertInGameTree(Node->left,newNode);
        }
        else if ((newNode->game_Id) == (Node->game_Id))
        {
            // there is a possibilty that the data set contains the duplication
            // cout << "The id: " << newNode->game_Id << " is already present in the Games tree" << endl; 
            delete newNode;
            newNode = nullptr;
            return;
        }
    }
}


void GameNodeTree:: showGameDetails(gameNode*& Root,string id){
    if (root == nullptr)
    {
        return;
    }
    else{
        if (id > Root->game_Id)
        {
            showGameDetails(Root->right,id);
        }
        else if (id < Root->game_Id)
        {
            showGameDetails(Root->left,id);
        }
        else{
            string gameName;
            cout <<  "Name of the Game: "  << Root->gameName << endl;
            cout << "Developer: " << Root->developer << endl;
            cout << "Publisher: " << Root->publisher << endl;
            cout << "Size of File: " << Root->sizeOfFile << endl;
            cout << "Download Count: " << Root->downloadCount << endl;
        } 
    }
    
}
    
void  GameNodeTree:: inorder(gameNode* root){
    if (root == nullptr)
    {
        return;
    }
    else{
        inorder(root->left);
        inorder(root->right);
    }
    

}

class GamesPlayedClassNode{
    public:
    GamesPlayedClassNode();
    GamesPlayedClassNode(string gId,string  hPlayed,string aUnlocked);

    string gameId;
    double hoursPlayed;
    int achievementsUnlocked;
    GamesPlayedClassNode *left;
    GamesPlayedClassNode *right;
};

class GamesPlayedClassNodeTree{
    public:

    GamesPlayedClassNode* root;

    GamesPlayedClassNodeTree();

    void deleteGamesPlayedTree(GamesPlayedClassNode*& Root);

    void insertInGamesPlayedTree(GamesPlayedClassNode *& Node,GamesPlayedClassNode *& newNode);

    GamesPlayedClassNode* searchGamePlayedNode(string id,GamesPlayedClassNode *&);

    void  showGamePlayed(GamesPlayedClassNode*& Root,GameNodeTree &t);

    void inorder(GamesPlayedClassNode*& Root);

    GamesPlayedClassNode* deleteNode(GamesPlayedClassNode*& Root,string id);

    GamesPlayedClassNode* findMin(GamesPlayedClassNode*);

    void contentsCopy(GamesPlayedClassNode*&,GamesPlayedClassNode*&);

    ~GamesPlayedClassNodeTree();
};


GamesPlayedClassNode :: GamesPlayedClassNode(){
        left = nullptr;
        right = nullptr;
    }

GamesPlayedClassNode ::GamesPlayedClassNode(string gId,string  hPlayed,string aUnlocked){
        left = nullptr;
        right = nullptr;
        gameId = gId;
        stringstream h(hPlayed);
        h >> hoursPlayed;
        stringstream f(aUnlocked);
        f >> achievementsUnlocked;
    }

GamesPlayedClassNodeTree :: GamesPlayedClassNodeTree(){
    root = nullptr;
}

void GamesPlayedClassNodeTree :: deleteGamesPlayedTree(GamesPlayedClassNode*& Root){
    
    if (Root == nullptr)
    {
        return;
    }
    
    else{
        deleteGamesPlayedTree(Root->left);
        deleteGamesPlayedTree(Root->right);
        delete Root;
        Root  = nullptr;
    }
}

void GamesPlayedClassNodeTree :: insertInGamesPlayedTree(GamesPlayedClassNode *& Node,GamesPlayedClassNode *& newNode){

    if (Node == nullptr){
        return;
    }

    else{
        if ( newNode->gameId > (Node->gameId) )
        {
            insertInGamesPlayedTree(Node->right,newNode);
        }
        else if ( (newNode->gameId) < (Node->gameId) )
        {
            insertInGamesPlayedTree(Node->left,newNode);
        }
        else if ( (newNode->gameId) ==  (Node->gameId) )
        {
            // there is a possibilty that the data set contains the duplication
            cout << "The id: " << newNode->gameId << " , " << newNode->achievementsUnlocked << newNode->hoursPlayed << " is already present in the game played tree" << endl; 
            delete newNode;
            newNode = nullptr;
            return;
        }
    }
}


GamesPlayedClassNode* GamesPlayedClassNodeTree :: searchGamePlayedNode(string id,GamesPlayedClassNode *& Node){
    if (Node == nullptr)
    {
        return nullptr;
    }
    else{
        if ( id > (Node->gameId) )
        {
            return searchGamePlayedNode(id,Node->right);
        }
        else if ( id < (Node->gameId) )
        {
            return searchGamePlayedNode(id,Node->left);
        }
        else
        {
            return Node;
        }
    }
}

void GamesPlayedClassNodeTree :: showGamePlayed(GamesPlayedClassNode*& Root,GameNodeTree &t)
{
    if (Root == nullptr)
    {
        return;
    }
    else{
        showGamePlayed(Root->left,t);
        cout << endl ;
        cout<< "Game ID: " << Root->gameId << endl;
        cout << "Hours Played: " << setprecision(17) <<Root->hoursPlayed << endl;
        cout << "Achievements Unlocked: " << Root->achievementsUnlocked << endl;
        t.showGameDetails(t.root,Root->gameId);
        cout << endl ;
        showGamePlayed(Root->right,t);
    }

}

void GamesPlayedClassNodeTree :: inorder(GamesPlayedClassNode*& Root){
    if (Root != nullptr)
    {
        inorder(Root->left);
        cout << Root->gameId << " ";
        inorder(Root->right);
    }
    
}

GamesPlayedClassNode* GamesPlayedClassNodeTree:: findMin(GamesPlayedClassNode* root){
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
    
}

void GamesPlayedClassNodeTree:: contentsCopy(GamesPlayedClassNode*& g1, GamesPlayedClassNode*& g2){
    g1->gameId = g2->gameId;
    g1->hoursPlayed = g2->hoursPlayed;
    g1->achievementsUnlocked = g2->achievementsUnlocked;
}

GamesPlayedClassNode* GamesPlayedClassNodeTree:: deleteNode(GamesPlayedClassNode*& Root,string id){
     if( Root == nullptr){
        return nullptr;
    }
    else
    {
        
        if (id > Root->gameId)
        {
            Root->right =  deleteNode(Root->right,id);
        }
        else if (id < Root->gameId)
        {
            Root->left =  deleteNode(Root->left,id);
        }
        else{
            if (Root->left == nullptr && Root->right == nullptr)
            {
                delete Root;
                cout << "Root is  a leaf node" << endl;
                return nullptr;
            }
            else if (Root->left == nullptr)
            {
                cout << "Root has right node" << endl;
                GamesPlayedClassNode* backup = Root->right;
                delete Root;
                Root = nullptr;
                return backup;

            }
            else if (Root->right == nullptr)
            {
                cout << "Root has left node" << endl;
                GamesPlayedClassNode* backup = Root->left;
                delete Root;
                Root = nullptr;
                return backup;
            }
            else{
                cout << "Root is a full node" << endl;
                GamesPlayedClassNode* temp = findMin(Root->right);
                Root->gameId = temp->gameId;
                Root->right =  deleteNode(Root->right,temp->gameId); 
            }
        }
    }
    return Root;
}


GamesPlayedClassNodeTree :: ~GamesPlayedClassNodeTree(){
        deleteGamesPlayedTree(root);
        // cout << "Game Played Tree Desctruction Done" << endl;
}


class playerNode{
    public:
    string playerID;
    string playerName;
    string phoneNumber;
    string email;
    string password;
    playerNode *left;
    playerNode *right;
    int totalGamesPlayed;
    GamesPlayedClassNodeTree gamePlayed;

    playerNode();
    playerNode(string pass,string mail,string pNumber, string pName,string pId);
};

class playerNodeTree{
    public:
    playerNode* root;
    
    playerNodeTree();

    void deletePlayerTree(playerNode*& Root);
    
    void insertInPlayerTree(playerNode *& Node,playerNode *& newNode);

    playerNode* playersSearch(string id,playerNode*& );

    void showPath(string id,playerNode*&);

    int layerNumber(playerNode*& ,string , int);

    void inorder(playerNode*& root);

    playerNode* findMin(playerNode*);

    void contentsCopy(playerNode*&,playerNode*&);

    playerNode* deleteNode(playerNode*&,string id);

    ~playerNodeTree();
};

playerNode :: playerNode(){
        left = nullptr;
        right = nullptr;
    }

playerNode :: playerNode(string pId,string pName,string pNumber, string mail,string pass){
    left = nullptr;
    right = nullptr;
    playerID = pId;
    playerName = pName;
    phoneNumber = pNumber;
    email = mail;
    password = pass;
    totalGamesPlayed = 0;
}
    
playerNodeTree :: playerNodeTree(){
    root = nullptr;
}

void playerNodeTree :: deletePlayerTree(playerNode*& Root){
    
    if (Root == nullptr)
    {
        return;
    }
    
    else{
        deletePlayerTree(Root->left);
        deletePlayerTree(Root->right);
        delete Root;
        Root  = nullptr;
    }
}

void playerNodeTree ::insertInPlayerTree(playerNode *& Node,playerNode *& newNode){

    if (Node == nullptr){
        Node = newNode;
        return;
    }

    else{
        if ( newNode->playerID > (Node->playerID) )
        {
            insertInPlayerTree(Node->right,newNode);
        }
        else if ( (newNode->playerID) < (Node->playerID) )
        {
            insertInPlayerTree(Node->left,newNode);
        }
        else{
            // there is a possibilty that the data set contains the duplication
            cout << "The id: " << newNode->playerID << " is already present in the player tree" << endl; 
            delete newNode;
            newNode = nullptr;
            return;
        }
    }
}

playerNode* playerNodeTree :: playersSearch(string id,playerNode*& root){
    if (root == nullptr)
    {
        return nullptr;
    }
    else{
        if (id > root->playerID)
        {
            return playersSearch(id, root->right);
        }
        else if (id < root->playerID)
        {
            return playersSearch(id,root->left);
        }
        else{
            // node is found
            return root;
        }
    }
}

int playerNodeTree :: layerNumber(playerNode*& Root,string id , int i){
    if (Root == nullptr)
    {
        return 0;
    }
    else{
        if (id > Root->playerID)
        {
            return layerNumber(Root->right,id,i + 1);
        }
        else if (id < root->playerID)
        {
            return layerNumber(Root->left,id,i + 1);
        }
        else{
            // node is found
            return i;
        }
    }
    
}

void playerNodeTree :: showPath(string id,playerNode*& Root){

    if (root == nullptr)
    {
        return;
    }
    else{
        cout << Root->playerID << endl;
        if (id > Root->playerID)
        {
            showPath(id,Root->right);
        }
        else if (id < Root->playerID)
        {
            showPath(id,Root->left);
        }
    }
}

void playerNodeTree :: inorder(playerNode*& root){
    if(root != nullptr){
        inorder(root->left);
        cout << root->playerID << " ";
        // cout << "Game Played Id's: " << endl;
        // root->gamePlayed.inorder(root->gamePlayed.root);
        // cout << endl;
        inorder(root->right);
    }
}

playerNode* playerNodeTree:: findMin(playerNode* Root){
    while (Root->left != nullptr)
    {
        Root = Root->left;
    }
    return Root;

}

void playerNodeTree :: contentsCopy(playerNode*& n1, playerNode*& n2){

    n1->email = n2->email;
    n1->password = n2->password;
    n1->phoneNumber = n2->phoneNumber;
    n1->playerID = n2->playerID;
    n1->playerName = n2->playerName;
    n1->totalGamesPlayed = n2->totalGamesPlayed;
}

playerNode* playerNodeTree:: deleteNode(playerNode*& Root,string id){
    if( Root == nullptr){
        return nullptr;
    }
    else
    {
        
        if (id > Root->playerID)
        {
            Root->right =  deleteNode(Root->right,id);
        }
        else if (id < Root->playerID)
        {
            Root->left =  deleteNode(Root->left,id);
        }
        else{
            if (Root->left == nullptr && Root->right == nullptr)
            {
                cout << "Root is  a leaf node" << endl;
                Root->gamePlayed.deleteGamesPlayedTree(Root->gamePlayed.root);
                delete Root;
                return nullptr;
            }
            else if (Root->left == nullptr)
            {
                cout << "Root has right node" << endl;
                playerNode* backup = Root->right;
                Root->gamePlayed.deleteGamesPlayedTree(Root->gamePlayed.root);
                delete Root;
                return backup;

            }
            else if (Root->right == nullptr)
            {
                cout << "Root has left node" << endl;
                playerNode* backup = Root->left;
                Root->gamePlayed.deleteGamesPlayedTree(Root->gamePlayed.root);
                delete Root;
                return backup;
            }
            else{
                cout << "Root is a full node" << endl;
                playerNode* temp = findMin(Root->right);
                contentsCopy(Root,temp);
                Root->gamePlayed.deleteGamesPlayedTree(Root->gamePlayed.root);
                Root->gamePlayed.root = temp->gamePlayed.root;
                temp->gamePlayed.root = nullptr;
                Root->right =  deleteNode(Root->right,temp->playerID); 
            }
        }
    }
    return Root;
}

playerNodeTree :: ~playerNodeTree(){
    deletePlayerTree(root);
    cout << "PLayer Node Tree Desctruction Done" << endl;
}

class queueNode{
    public:
    playerNode* Node;
    queueNode* next;

    queueNode(playerNode* node){
        Node = node;
        next = nullptr;
    }
};

class Queue{
    public:
    queueNode* front;
    queueNode* rear;
    Queue(){
        front = nullptr;
        rear = nullptr;

    }

    void Enqueue(playerNode* node){
        queueNode* newNode = new queueNode(node);
        if (front == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = rear->next;
        }
    }

    playerNode* deqeue(){
        if (front == nullptr)
        {
            return nullptr;
        }
        else{
            playerNode* backupPlayer = front->Node;
            queueNode* queueBackup = front;
            front = front->next;
            delete queueBackup;
            if (front == nullptr)
            {
                rear = nullptr;
            }
            return backupPlayer;
        }
    }
    bool isEmpty(){
        return front == nullptr;
    }
};


class players
{
    public:
        string id;
        int gamesPlayed;
        players* left;
        players* right;

    players(string ID, int gp){
        id = ID;
        gamesPlayed = gp;
        left = nullptr;
        right = nullptr; 
    }
};


class topNplayers{
    public:
    players* root;
    topNplayers():root(nullptr){}

    void insertInTopNPlayers(players*& playersRoot, string& playerId, int& gamesPlayed){
        if (playersRoot == nullptr)
        {
            playersRoot = new players(playerId,gamesPlayed);
            return;
        }
        else{
            if (playersRoot->gamesPlayed > gamesPlayed)
            {
                insertInTopNPlayers(playersRoot->left, playerId,gamesPlayed);
            }
            else if (playersRoot->gamesPlayed < gamesPlayed)
            {
                insertInTopNPlayers(playersRoot->right, playerId,gamesPlayed);
            }
            else{
                playersRoot->id += "," + playerId;
            }            
        }
    }

    void inorder(players*& Root, int& n){
        if (Root == nullptr || n <= 0)
        {
            return;
        }
        else{
            inorder(Root->right,n);
            if (n > 0)
            {
                cout << "PLayer with Id: " << Root->id << " has Played: " << Root->gamesPlayed << endl;
                n--;
            }
            inorder(Root->left,n);            
        }
    }

    void deleteTopNPlayer(players*& Root){
        if (Root == nullptr)
        {
            return;
        }
        
        else{
            deleteTopNPlayer(Root->left);
            deleteTopNPlayer(Root->right);
            delete Root;
            Root  = nullptr;
        }
    }
    ~topNplayers(){
        deleteTopNPlayer(root);
        root = nullptr;
    }
};  



void setGameTree(GameNodeTree& t){
    ifstream file("Games.txt");
    string line;
    if (!file.is_open()) {
        cout << "Check the File Destination." << endl;
        exit(0);
    }
    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        gameNode* temp = new gameNode(ss);
        t.insertInGameTree(t.root,temp);
    }
    file.close();
}

string getSubString(string& str){
    if (str.length() == 0)
    {
        return "\0";
    }
    else{
        string temp;
        while (!str.empty() && str[0] != ',' && str[0] != '\n')
        {
            temp += str[0];
            str.erase(0, 1);
        }
        if (!str.empty()) {
            str.erase(0, 1);
        }
        return temp;
    }
    
}

void findLayerNumber(playerNodeTree &p){
    string playerId = "";
    cout << "Enter the Player Id for which you want to find the layer number: ";
    cin >> playerId;
    int nLayer = p.layerNumber(p.root,playerId,1);
    if (nLayer == 0)
    {
        cout << "Not Found" << endl;
    }
    else{
        cout << "PLayer with id: " << playerId << " is found at layer number: " << nLayer << endl;
    }
    

}

void setPlayerTreeFromTxt(playerNodeTree &p){
    ifstream file("Players.txt");
    if (!file.is_open())
    {
        cout << "Check the File Destination." << endl;
        exit(0);
    }
    string line;
    while (getline(file,line))
    {
        int random = rand() % 1001;
        if (random < 440){
            continue;
        }
        else{
            playerNode* newPlayerNode = new playerNode(getSubString(line),getSubString(line),getSubString(line),getSubString(line),getSubString(line));
            cout << newPlayerNode->playerID << endl;
            p.insertInPlayerTree(p.root,newPlayerNode);
            while (line.length() > 0)
            {
                newPlayerNode->totalGamesPlayed++;
                GamesPlayedClassNode* newNode = new GamesPlayedClassNode(getSubString(line),getSubString(line),getSubString(line));
                newPlayerNode->gamePlayed.insertInGamesPlayedTree(newPlayerNode->gamePlayed.root,newNode);
            }
        }
        
    }
}

void setPlayerTreeFromCsv(playerNodeTree &p){
    ifstream file("Players.csv");
    if (!file.is_open())
    {
        cout << "Check the File Destination." << endl;
        exit(0);
    }
    string line;
    while (getline(file,line))
    {
        playerNode* newPlayerNode = new playerNode(getSubString(line),getSubString(line),getSubString(line),getSubString(line),getSubString(line));
        cout << newPlayerNode->playerID << endl;
        p.insertInPlayerTree(p.root,newPlayerNode);
        while (line.length() > 0)
        {
            GamesPlayedClassNode* newNode = new GamesPlayedClassNode(getSubString(line),getSubString(line),getSubString(line));
            newPlayerNode->gamePlayed.insertInGamesPlayedTree(newPlayerNode->gamePlayed.root,newNode);
        }
    }
}



void insertionUsingInput(playerNodeTree &p){
    char ch;
    cout << "In which Data Structure you want to add a) player, b)game played: " ;
    cin >> ch;
    if (ch == 'a'){
        playerNode* newNode = new playerNode;
        cout << "Enter the following details For the new Player\n ";
        cout << "Enter PlayerId: ";
        cin >> newNode->playerID;
        cout << "Enter Email: ";
        cin >> newNode->email;
        cout << "Enter password: ";
        cin >> newNode->password;
        cout << "Enter phone#: ";
        cin >> newNode->phoneNumber;
        cout << "Enter playerName: ";
        cin >> newNode->playerName;
        p.insertInPlayerTree(p.root,newNode);

    }
    else if(ch == 'b') {
        string playerId = "";
        cout << "\n\nEnter the Player id For which you want to show the path: ";
        cin >> playerId;
        playerNode* temp =  p.playersSearch(playerId,p.root);
        
        if (temp == nullptr)
        {
            cout << "You enetered an invalid player id" << endl;
        }
        else{
            cout << "Enter the given below details to add a new game\n";
            GamesPlayedClassNode* newNode = new GamesPlayedClassNode;
            cout << "Enter the id of the game played game: ";
            cin >> newNode->gameId;
            cout << "Enter the achievements that are unlocked by the player in the game: ";
            cin >> newNode->achievementsUnlocked;
            cout << "Enter the hours played by the player in the game: ";
            cin >> newNode->hoursPlayed;
            temp->gamePlayed.insertInGamesPlayedTree(temp->gamePlayed.root,newNode);
        }
    }
}

void pathShow(playerNodeTree& p){
    string playerId = "";
    cout << "Enter the Player id For which you want to show the path: ";
    cin >> playerId;
    
    playerNode* temp =  p.playersSearch(playerId,p.root);
    
    if (temp == nullptr)
    {
        cout << "You enetered an invalid player id" << endl;
    }
    else{
        cout << "This path is followed by the entered player Id" << endl;
        p.showPath(playerId,p.root);
    }
}

void hasPlayed(playerNodeTree &p){
    string playerId = "";
    cout << "Enter the Player Id: " ;
    cin >> playerId;
    
    playerNode* temp =  p.playersSearch(playerId,p.root);
    if (temp == nullptr)
    {
        cout << "You enetered an invalid player id" << endl;
    }
    else{
        string gameId = "";
        cout << "Enter the Game Id For which you want to check that the player has played or not: " << endl;
        cin >> gameId;
        GamesPlayedClassNode* temp2 = temp->gamePlayed.searchGamePlayedNode(gameId,temp->gamePlayed.root);
        if (temp2 == nullptr)
        {
            cout << "Player with id: " << playerId << " has not played a game with id: " << gameId << endl;
        }
        else{
            cout << "Player with id: " << playerId << " has played a game with id: " << gameId << endl;
        }
    }
}


void showDetails(playerNodeTree &p,GameNodeTree& t){
    string playerId = "";
    cout << "Enter the Player Id: " ;
    cin >> playerId;
    
    playerNode* temp =  p.playersSearch(playerId,p.root);
    
    if (temp == nullptr)
    {
        cout << "You enetered an invalid player id" << endl;
    }
    else{
        temp->gamePlayed.showGamePlayed(temp->gamePlayed.root,t);
    }
}



void performDeletion(playerNodeTree& p,GameNodeTree& t ){
    
    string playerId = "";
    char op;
    cout << "Which operation you want to perform delete player or game played by the player. a) delete player b) delete game played.\n\n Enter a or b: ";
    cin >> op;
    cout << "Enter the Player Id: ";
    cin >> playerId;
    if (op == 'a')
    {
        p.deleteNode(p.root,playerId);        
    }
    else if (op == 'b')
    {
        playerNode* temp = p.playersSearch(playerId,p.root);
        if (temp == nullptr)
        {
            cout << "This player with this id is not found" << endl;
            return;
        }
        else{
            string gameid = "";
            temp->gamePlayed.showGamePlayed(temp->gamePlayed.root,t);
            cout << "Enter the id of the game you want to delete: ";
            cin >> gameid;
            temp->gamePlayed.deleteNode(temp->gamePlayed.root,gameid);
        }
    }
    
}


void searchAPlayer(playerNodeTree& p,GameNodeTree& t){
    string playerId = "";
    char op;
    cout << "Which operation you want to perform a) Search player b) Search game played.\n\n Enter a or b: ";
    cin >> op;
    cout << "Enter the Player Id: ";
    cin >> playerId;
    playerNode* temp = p.playersSearch(playerId,p.root);
    if (temp == nullptr)
    {
        cout << "Player with the input id is not present" << endl;
        return;
    }
    else{
        if (op == 'a')
        { 
            cout << "Player with id: " << temp->playerID << " is found" << endl;
        }
        else if(op == 'b' )
        {
            string gameid = "";
            temp->gamePlayed.showGamePlayed(temp->gamePlayed.root,t);
            cout << "Enter the id of the game you want to delete: ";
            cin >> gameid;
            if (temp->gamePlayed.searchGamePlayedNode(gameid , temp->gamePlayed.root))
            {
                cout << "Game with id " << gameid << " is present in the " << " games played by: " << temp->playerID << endl;
            }
            else{
                cout << "Game with id " << gameid << " is not present in the " << " games played by: " << temp->playerID << endl;
            }
            
        }
    }
}

void preorderGamePlayedSave(GamesPlayedClassNode*& Root, ofstream& file){
    if (Root == nullptr)
    {
        return;
    }
    else{
        file << ',' << Root->gameId << ',' << Root->hoursPlayed  << ',' << Root->achievementsUnlocked;
        preorderGamePlayedSave(Root->left, file);
        preorderGamePlayedSave(Root->right, file);
    }
}

void preorderPlayerSave(playerNode*& Root,ofstream& file){
    if (Root == nullptr)
    {
        return;
    }
    else{
        file << Root->playerID << "," << Root->playerName << ',' << Root->phoneNumber << ',' << Root->email << ',' << Root->password;
        preorderGamePlayedSave(Root->gamePlayed.root,file);
        file << '\n';
        preorderPlayerSave(Root->left,file);
        preorderPlayerSave(Root->right,file);
    }
    
}

void savetoCsv(playerNodeTree& p){
    ofstream file("Players.csv");
    if (! file.is_open()) 
    {
        cout <<  "Players.csv file is the present in the destination" << endl;
        return;
    }
    else{
        preorderPlayerSave(p.root,file);
    }
}

void editInfo(playerNodeTree& p){
    string playerId;
    cout << "Which player id you want to want to edit the info: ";
    cin >> playerId;
    playerNode* temp = p.playersSearch(playerId,p.root);
    if (temp == nullptr)
    {
        cout << "The id you entered is not present in the player tree"; 
    }
    else{
        char op;
        cout << "What you want to update a) player id b) name c) email d) password e) phone#: ";
        cin >> op;
        
        if (op == 'a')
        {
            cout << "Enter a new id: ";
            cin >> playerId;
            if (playerId == temp->playerID)
            {
                return;
            }
            else{
                playerNode* newNode = new playerNode;
                p.contentsCopy(newNode,temp);
                temp->playerID = newNode->playerID;
                newNode->playerID = playerId;// new player id
                newNode->gamePlayed.root = temp->gamePlayed.root;
                temp->gamePlayed.root = nullptr;
                p.deleteNode(p.root,temp->playerID);
                p.insertInPlayerTree(p.root,newNode);
            }
            
        }

        else if (op == 'b')
        {
            cout << "Enter the new name: ";
            cin >> temp->playerName;
        }
        
        else if (op == 'c')
        {
            cout << "Enter the new email: ";
            cin >> temp->email;
        }
        
        else if (op == 'd')
        {
            cout << "Enter the new password: ";
            cin >> temp->password;
        }
        
        else if (op == 'e')
        {
            cout << "Enter the new phone#: ";
            cin >> temp->phoneNumber;
        }   
    }
}


void showNLayers(playerNode* Root){
    int nLayers;
    cout << "Upto how many layers you want to print: ";
    cin >> nLayers;
    if (Root == nullptr || nLayers <= 0)
    {
        cout << "The player Tree is not created yet or you entered the invalid size for the layers" << endl;
        return;
    }
    Queue players;
    players.Enqueue(Root);
    int presentLayer = 1;
    int totalNodesInTree = 1;
    while (nLayers >= presentLayer && players.isEmpty() == false)
    {
        Queue temp;
        int nodesInLayer = 0;
        while (players.isEmpty() == false)
        {
            temp.Enqueue(players.deqeue());
            nodesInLayer ++;

        }
        

        cout << "In layer " << presentLayer << " following are the node" << endl;

        totalNodesInTree += nodesInLayer;
        while (nodesInLayer > 0)
        {
            playerNode* temporary = temp.deqeue();
            cout << temporary->playerID << " ";
            if (temporary->left != nullptr)
            {
                players.Enqueue(temporary->left);
            }
            if (temporary->right != nullptr)
            {
                players.Enqueue(temporary->right);
            }
            
            nodesInLayer--;
        }

        presentLayer++;
        cout << endl << endl;
    }
    

    cout << "Total Nodes in the Tree: " << totalNodesInTree << endl;
    if (presentLayer <= nLayers)
    {
        cout << "Layer Limit was Reached, cannot go further!!!" << endl;
    }
}

void insertInTopPlayers(playerNode*& Root, topNplayers& topPlayersRoot){
    if (Root == nullptr)
    {
        return;
    }
    else{
        topPlayersRoot.insertInTopNPlayers(topPlayersRoot.root,Root->playerID,Root->totalGamesPlayed);
        insertInTopPlayers(Root->left,topPlayersRoot);
        insertInTopPlayers(Root->right,topPlayersRoot);
    }
    
}

void displayTopN(playerNode*& Root){
    int n;
    cout << "How many top players you want to see: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Invalid Value of n" << endl;
        return;
    }
    
    topNplayers p1;
    insertInTopPlayers(Root,p1);
    p1.inorder(p1.root,n);
}

int main(){
    srand(230034);
    GameNodeTree t;
    setGameTree(t);
    char op;
    playerNodeTree p;
    cout << "From which file you want to create the player tree a) csv b) txt: ";
    cin >> op;
    if (op == 'a')
    {
        setPlayerTreeFromCsv(p);
    }
    else
        setPlayerTreeFromTxt(p);
    op = ' ';
    do{
        cout << "\n\n  Available operations a) show details b) delete node c) has played d) Find Layer Number e) Show Path f) Search for a player g) show layer number h) Insert Using Input i) Save Data j) Show N layers k)Edit l) top n plays q) to quit\n";
        cout << "Which operation you want to perform: ";
        cin >> op;
        if (op == 'a')
        {
            showDetails(p,t);
        }
        else if (op == 'b')
        {
            performDeletion(p,t);
        }
        else if (op == 'c')
        {
            hasPlayed(p);
        }
        else if (op == 'd')
        {
            findLayerNumber(p);
        }
        else if (op == 'e')
        {
            pathShow(p);
        }
        else if (op == 'f')
        {
            searchAPlayer(p,t);
        }
        else if (op == 'g')
        {
            findLayerNumber(p);
        }
        else if (op == 'h')
        {
            insertionUsingInput(p);
        }
        else if (op == 'i')
        {
            savetoCsv(p);
        }
        else if (op == 'j')
        {
            showNLayers(p.root);
        }
        
        else if (op == 'k')
        {
            editInfo(p);
        }
        else if (op == 'l')
        {
            displayTopN(p.root);
        }  
    }while (op != 'q');
}