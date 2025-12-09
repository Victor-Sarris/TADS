import { DataTypes } from "sequelize";
import conectDB from "../../config/db.js";
import Collection from "../collection/collection.model.js";

const sequelize = await conectDB();
const Object = sequelize.define("Objects",{
    id: {type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true, allowNull: false},
    description: {type: DataTypes.STRING, allowNull: false},
    type: {type: DataTypes.STRING, allowNull: false},
    value: {type: DataTypes.FLOAT, allowNull: true},
    collectionId: {type: DataTypes.INTEGER, allowNull: false, references: {model: Collection, key: 'id'}},
});

Object.belongsTo(Collection)
Collection.hasMany(Object)

await Object.sync();
export default Object;