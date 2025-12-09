//definição dos dados
import { DataTypes } from "sequelize";
import conectDB from "../database/db.js";

const sequelize = await conectDB()

const Person = sequelize.define("Person",{
    // id: {type: DataTypes.INTEGER, defaultValue: 1},
    id: {type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true, allowNull: false },
    name: {type: DataTypes.STRING, allowNull: false,},
    email: {type: DataTypes.STRING, allowNull: false, unique: true,},
    password: {type: DataTypes.STRING, allowNull: false,},
    isAdmin: {type: DataTypes.BOOLEAN, defaultValue: false,},
    isActive: {type: DataTypes.BOOLEAN, defaultValue: true,},
});

await Person.sync()

//Parametros: nome do modelo, esquema, nome da coleção no MongoDB
export default Person;