<?php

use Appwrite\Client;
use Appwrite\Services\Storage;

$client = new Client();

$client
    ->setEndpoint('https://[HOSTNAME_OR_IP]/v1') // Your API Endpoint
    ->setProject('5df5acd0d48c2') // Your project ID
    ->setKey('919c2d18fb5d4...a2ae413da83346ad2') // Your secret API key
;

$storage = new Storage($client);

$result = $storage->getFile("[FILE_ID]");
