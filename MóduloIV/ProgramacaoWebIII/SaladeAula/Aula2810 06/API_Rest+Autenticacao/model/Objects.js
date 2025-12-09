import { DataTypes } from "sequelize";
import conectDB from "../database/db";
import Collection from "./Collection";

const sequelize = await conectDB();

const Object = sequelize.define("Object", {
    id: {type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true, allowNull: false },
    description: {type: DataTypes.STRING, allowNull: false},
    type: {type: DataTypes.STRING, allowNull: false},
    value: {type: DataTypes.FLOAT, allowNull: true},
});

Object.belongsTo(Collection)
Collection.hasMany(Object)

await Object.sync();
export default Object;