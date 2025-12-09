const express = require("express") // importando o express
const app = express() // é como se tivesse retornando uma instÂncia de uma importação express


app.get("/", (req, res)=>{
    res.send("Servidor funcionando!")
})

app.listen(8080, (err)=>{ // função de callback
    if(err){ // no caso, se tiver algum erro...
        console.log("Tem algo errado")
    } else{ // caso não tenha erro...
        console.log("Servidor on-line! :)")
    }
})
