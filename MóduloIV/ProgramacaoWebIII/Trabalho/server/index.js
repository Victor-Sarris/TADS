// server/index.js
import express from "express";
import "dotenv/config"
import cors from "cors"; // Você vai precisar instalar: npm install cors
import conectDB from "./database/db.js";
import publicRoutes from "./routes/public.js";
import privateRoutes from "./routes/private.js";

const app = express();
const PORT = 3000;

// Configuração para aceitar JSON e permitir que o Front (porta 5173) converse com o Back (porta 3000)
app.use(express.json());
app.use(cors()); 

// Conectar ao Banco
await conectDB();

// Rotas
app.use("/", publicRoutes);
app.use("/", privateRoutes);

app.listen(PORT, () => {
  console.log(`Servidor rodando em http://localhost:${PORT}`);
});