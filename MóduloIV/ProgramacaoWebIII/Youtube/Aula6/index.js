const express = require("express")
const app = express()

// app.get('/busca/:conteudo?', (req, res)=>{ // Não obrigatorio
app.get('/busca/:conteudo', (req, res)=>{
    var conteudo = req.params.conteudo || "nada foi buscado"
    if(conteudo){
        res.send(conteudo)
        console.log("conteudo: " + conteudo)
    }else{
        res.send("Sem parâmetros")
    }
})

app.get("/", (req, res)=>{
    var conteudo = req.query["busca"]
    if(conteudo){
        res.send(conteudo)
        console.log("conteudo: " + conteudo)
    }else{
        res.send("Sem parâmetros")
    }
})

app.get("/floriano", (req, res)=>{
    res.send("Campus Floriano")
})

app.get("/floriano/noticias", (req, res)=>{
    res.send("Campus Floriano | Notícias")
})

app.listen(8080, (err)=>{
    if(err){
        console.log("Servidor não pode ser executado" + err)
    }else{
        console.log("Servidor on-line!")
    }
})