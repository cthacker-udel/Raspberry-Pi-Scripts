let httpModule = require('https');

function process_data(thedata){

    console.log(`the data = ${thedata}`);

}

function modernGenerateNameV3() {

    let url = "https://random-word-api.herokuapp.com/word?number=2&swear=0";
    let data = '';

    httpModule.get(url, res => {

        res.on('data', theData => {
            data += theData;
        });

        res.on('end', () => {
            process_data(data);
        })

    })

}