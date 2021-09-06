let fetch = require('node-fetch');function modernGenerateRandomName(){

    let theVar = fetch("https://random-word-api.herokuapp.com/word?number=2&swear=0",{method: 'GET'}).then(function(response){

        if(response.ok){
            return response.text();
        }
        else{
            return new Error('Could not get data, invalid request');
        }
    });

    console.log(1);

}



modernGenerateRandomName();