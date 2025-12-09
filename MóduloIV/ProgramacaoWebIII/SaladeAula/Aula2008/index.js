const express = require("express")
// req = requisição do navegador
// res = requisição do servidor
// /?campo=valor
const app = express()
app.get("/", (req, res) => {
    var busca = req.query["campo"]
    console.log("Cliente acessou rota raiz")
    var saida = "Query: " + busca
    res.send(saida)
});
app.get("/IFPI",(req, res) => {
    res.send("Rota IFPI")
})
app.get("/IFPI/Floriano/:busca",(req, res) => {
    var busca = req.params.conteudo
    res.send("IFPI Campus Floriano")
    res.send("Parametro:", busca)
})
app.get("/IFPI/Floriano",(req, res) => {
    res.send("IFPI Campus Floriano")
})

app.get("/IFPI/Floriano/:conteudo",(req, res) => { // parametro opicional
    var conteudo = req.params.conteudo
    var saida = "Parametro" + conteudo
    res.send(saida)
})
app.get("/ifpi/:conteudo?", (req, res) =>{ // parametro obrigatorio
    var conteudo = req.params.conteudo
    var saida = "Parametro" + conteudo
    res.send(saida)
})

app.listen(8080, (err)=>{

})