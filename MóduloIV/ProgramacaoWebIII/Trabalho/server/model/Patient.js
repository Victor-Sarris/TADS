import { DataTypes } from "sequelize";
import conectDB from "../database/db";
import User from "./User.js";

const sequelize = await conectDB();

const Patient = sequelize.define("Patient", {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    autoIncrement: true,
    allowNull: false,
  },
  name: { type: DataTypes.STRING, allowNull: false },
  email: { type: DataTypes.STRING, allowNull: false },
  password: { type: DataTypes.STRING, allowNull: false },
  phone: { type: DataTypes.INTEGER, allowNull: false },
  gender: { type: DataTypes.STRING, allowNull: true },
  userId: {
    type: DataTypes.INTEGER,
    allowNull: false,
    references: {
      model: User,
      key: "id",
    },
  },
});

User.hasOne(Patient, { foreignKey: "userId" });
Patient.belongsTo(User, { foreignKey: "userId" });

export default Patient;
