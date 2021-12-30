const config =require('./config');
const superagent= require('superagent')



const fun=(city,callback)=>{  //callback is in the calling function


const full=config.adress.base +city+config.adress.key;

superagent.get(full).end( (err,res)=>{
    
    if(err)
    callback(err,undefined);    // sends error to the calling fuction
    else 
    callback(undefined,res.body); //sends body of the data to calling function
})
}

module.exports=fun;