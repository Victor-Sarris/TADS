// conexao com banco de dados (moongo db)
import mongoose from "mongoose";

const conectDB = async () => {
    try {
        await mongoose.connect(process.env.MONGODB_URI)
        console.log("Conectando ao MongoDB!");
    } catch (erro) {
        console.log(`Conexao com banco de dados falhou | erro: ${erro}`);
    }
}

export default conectDB;