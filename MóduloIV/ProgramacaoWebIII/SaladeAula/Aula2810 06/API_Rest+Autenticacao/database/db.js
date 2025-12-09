import { Sequelize } from "sequelize";
import path from "node:path"

let sequelize;

const conectDB = async () => {
  try {
    const dbpath = process.env.SQLITE_PATH;
    
    sequelize = new Sequelize({
      dialect: "sqlite",
      storage: path.resolve(dbpath),
      logging: false
    });

    sequelize.authenticate()

    console.log("SQLite3 foi conectado!!! :)");
    return sequelize;
  } catch (error) {
    console.error("Erro ao conectar ao SQLite3: :(", error);
    return null;
  }
};

export default conectDB;