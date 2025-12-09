const express = require("express")
const app = express()
const controller = require("./controller")

app.set("view engine", "ejs") // ejs (para saida de paginas personalizadas)
app.get("/:texto", (req, res)=>{
    var texto = req.params.texto
    res.render("pagina", // template a ser renderizado
        {
        "texto": texto // valor da pagina a ser renderizado
    })
})
app.use("/teste", controller)

app.listen(8080, (err)=>{
    console.log("Servidor onlline")
});