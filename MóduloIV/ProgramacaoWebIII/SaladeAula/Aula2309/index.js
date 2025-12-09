import 'dotenv/config';
import express from "express";
import conectDB from "./db.js";
import publicRoutes from "./routes/public.js"

const PORT = 3000;
const app = express();
app.use(express.json()); //necessário para receber json via API.

app.use('/', publicRoutes);

// esta funcao é assincrona e vamos tratar a "Promisse"
conectDB()
    .then(() => {
        app.listen(PORT, (erro) => {
            if (!erro) {
                console.log(`Servidor online. http://localhost:${PORT}/`)
            } else {
                console.log(`Não foi possível executar: ${erro}`)
            }
        })
    })
    .catch((erro) => {
        console.log(`Erro de conexao com o MongoDB: ${erro}`);
    });