import requests
import urllib.request
import json
import hashlib
import merkletools
import random
import time
import socket

NONCE_MAX = 4294967296
API_URL = "https://blockchain.info/latestblock"
TX_KEY = "txIndexes"
PREVHASH_KEY = "hash"
HASH_ATTEMPTS = 15000
THRESHOLD = 3

IP = '127.0.0.1'
PORT = 42069

with urllib.request.urlopen(API_URL) as url:
    data = json.loads(url.read().decode())
    prevHash = data[PREVHASH_KEY]
    transactions = data[TX_KEY]

    #merkle hash transactions
    mt = merkletools.MerkleTools(hash_type="sha256")
    for transaction in transactions:
        mt.add_leaf(hex(transaction), True)
    mt.make_tree()
    is_ready = False;
    while not is_ready:
        is_ready = mt.is_ready
    root_value = mt.get_merkle_root();

    #DEBUG
    #print ("Merkle Root: " + root_value)
    #print("Previous Hash: " + prevHash)
    #print("Time: " + str(data["time"]))
    #print("Transactions: ")
    #print(transactions)    
    
    start_time = time.time()

    #set up threshold
    comp = (THRESHOLD) * '0'

    #attempt HASH_ATTEMPTS times to find the correct hash
    hashdict = {}
    for i in range(HASH_ATTEMPTS):
        nonce = random.randrange(NONCE_MAX)
        firstpass = hashlib.sha256(((root_value+str(nonce)).encode('utf-8')))
        secondpass = hashlib.sha256()
        firstpass.hexdigest()
        secondpass.update(firstpass.digest())
        secondpass.hexdigest()
        h = secondpass.hexdigest()
        #only allows hash through if it fulfills a certain threshold
        if str(h)[:THRESHOLD]==comp:
            hashdict[nonce] = h

    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    time_elapsed = time.time() - start_time;
    for h in hashdict:
        message = str(hashdict[h]) + " " + str(int(time_elapsed*1000));
        s.sendto(message.encode('utf-8'), (IP, PORT))
    #DEBUG    
        #print (str(h) + ": " + str(hashdict[h]))
    #print("--- %s seconds ---" % (time.time() - start_time))
