This is the CSCI 201 Final Project for -  

Jason Yik, jyik@usc.edu

Nick Chen, nickchen@usc.edu

Ada Toydemir, toydemir@usc.edu

Haoda Wang, haodawan@usc.edu

Kai-Chin Hsu, kaichinh@usc.edu

Lauren Shen, laurenys@usc.edu


Project Proposal:

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
